#pragma once
#include <windows.h>

// ��ȡNTͷ
#define		NTHEADER_T(lpBuff) (PIMAGE_NT_HEADERS32)((PBYTE)(lpBuff) + ((PIMAGE_DOS_HEADER)(lpBuff))->e_lfanew)
#define		NTHEADER(lpBuff)	(NTHEADER_T(lpBuff))

// ��ȡNT�ļ�ͷ
#define		NTFILEHEADER(lpBuff)	((NTHEADER(lpBuff))->FileHeader) 

// ��ȡ��չNTͷ
#define		NTOPTIONALHEADER_T(lpBuff) &(((PIMAGE_NT_HEADERS32)((PBYTE)lpBuff +	\
										((PIMAGE_DOS_HEADER)lpBuff)->e_lfanew))->OptionalHeader)

#define		NTOPTIONALHEADER(lpBuff)	(NTOPTIONALHEADER_T(lpBuff))

#define		SECTION_HEAD	1

typedef	struct _Typeoffset
{
	WORD wOffset : 12;
	WORD wType : 4;
}Typeoffset,*PTypeoffset;


/// �����ε�����ת����ʮ�������ַ���
void	byteArr2HexStr(const LPBYTE& lpbArr,
					   DWORD dwBSize,TCHAR* pszHexStr,
					   const TCHAR wcSpace = 0
					   );

/// ʵ�ʴ�Сת������С , 
DWORD size2AligentSize(DWORD n64FileSize,DWORD n64Aligent);

/// �ж��Ƿ���PE�ļ�
BOOL	IsPEFile(const LPVOID lpBuff);

///��ȡPEͷָ��
const PIMAGE_NT_HEADERS32 GetPEHeader(const LPVOID& lpBuff);

///��ȡ��չͷ��ָ��
const PIMAGE_OPTIONAL_HEADER32	GetOptionalHeader(const LPVOID& lpBuff);

///��ȡͷ����С
//DWORD	GetHeadSize(const LPVOID lpFile);
/// ��ȡͷ����С
DWORD	GetHeaderSize(const LPBYTE lpFile);
///��ȡͷ�����ڴ��еĴ�С
DWORD	GetHeadSizeOnMem(const LPVOID lpFile);


/// RVAתOffset
DWORD64	RVA2Offset(const LPVOID lpFile,DWORD64 dwRVA);
/// �ļ�ƫ��תRVA
//DWORD	Offset2RVA(const LPBYTE lpFile,DWORD dwOffset);

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
///�༭������Ϣ
BOOL	EditSectionInfo(const LPVOID lpFile,
						PIMAGE_SECTION_HEADER pSec,
						const TCHAR* pszName,
						DWORD dwSize,
						DWORD dwRVA,
						DWORD dwChara
						);
BOOL	EditSectionInfo(const LPVOID lpFile,
						PIMAGE_SECTION_HEADER pSec,
						const char* pszName,
						TCHAR* pszSize,
						TCHAR* pszRVA,
						TCHAR* pszChara
						);
// ������
BOOL	EditSectionName(PIMAGE_SECTION_HEADER pSec ,const TCHAR* pszName);
BOOL	EditSectionName(PIMAGE_SECTION_HEADER pSec ,const char* pszName);
// ���δ�С(δ�ļ�����)
BOOL	EditSectionFileSize(const LPVOID lpFile,PIMAGE_SECTION_HEADER pSec ,DWORD dwSize);
BOOL	EditSectionFileSize(const LPVOID lpFile,PIMAGE_SECTION_HEADER pSec ,TCHAR* pszSize);
// �����ڴ�ƫ��
BOOL	EditSectionRVA(PIMAGE_SECTION_HEADER pSec ,DWORD dwRVA);
BOOL	EditSectionRVA(PIMAGE_SECTION_HEADER pSec ,TCHAR* pszRVA);
// ��������
BOOL	EditSectionChara(PIMAGE_SECTION_HEADER pSec ,DWORD dwChara);
BOOL	EditSectionChara(PIMAGE_SECTION_HEADER pSec ,TCHAR* pszChara);

// ���ε��ļ�ƫ��
BOOL	EditSectionFileOffset(PIMAGE_SECTION_HEADER pSec,TCHAR* pszOffset);
BOOL	EditSectionFileOffset(PIMAGE_SECTION_HEADER pSec,DWORD	dwOffset);
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/// ���һ���µ�����.
/// ����1,pNewSection�������ε�λ��
/// ����2,pNewSection�������ε�λ��,lpFile���Ծɿռ�������䲢�޸ĵ��µ��ڴ�ռ�
PIMAGE_SECTION_HEADER	AddSection(_Inout_ LPBYTE& lpFile,DWORD& dwSize,const TCHAR* pszName,DWORD	dwNameLen,DWORD	dwSecSize, unsigned char *newSection);

/// ��ȡ���һ������
PIMAGE_SECTION_HEADER	GetLastSection(const LPBYTE lpFile);

/// ɾ��ָ��λ�õ�����
BOOL	DeleteSection(LPBYTE& lpFile,DWORD& dwSize , DWORD	dwIndex);

///��ȡָ������
PIMAGE_SECTION_HEADER	GetSection(const LPBYTE lpFile,DWORD dwIndwx);

///��ȡRVA����һ������,����������εĵ�ַ, û���򷵻�NULL,����SECTION_HEADʱָ����ͷ��
PIMAGE_SECTION_HEADER	GetSectionRVA(const LPVOID lpFile,DWORD64 dwRva);
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
