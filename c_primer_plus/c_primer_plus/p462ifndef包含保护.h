// �����嵥 16.10
#ifndef NAMES_H_
#define NAMES_H_

// ����
#define SLEN 32

// �ṹ����
struct names_st
{
	char first[SLEN];
	char last[SLEN];
};

// ���Ͷ���
typedef struct names_st names;

// ����ԭ��
void get_names (names * pn);
void show_names (const names * pn);

#endif