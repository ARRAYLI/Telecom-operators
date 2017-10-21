#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int BSD2_DATA_BLOCKS = 0;     //����ȫ�ֱ���BSD2_DATA_BLOCKS����6��ģ������
typedef struct space
{
	char space[3];
}Space;

//��ʼ���ո�ṹ�壻
void Init(FILE* sp)
{
	Space s;
	int i = 0;
	for (; i < 3; i++)
	{
		s.space[i] = ' ';
	}
	fwrite(&s.space, sizeof(Space), 1, sp);
}

//�����ṹ�壻
typedef struct _DATA
{
	char flag1[2];
	char space1[3];
	char ZCALL[10];
	char space2[3];
	char flag2[2];
	char space3[3];
	char CALLED[16];
	char space4[3];
	char START_TIME[6];
	char space5[3];
	char END_TIME[6];
	char space6[3];
	char COM_DATA[4];
	char space7[3];
	char COM_TIMT_LENGTH[6];
	char space8[3];
	char flag3[4];
	char space9[3];
	char OUT_MID_CON[4];
	char space10[3];
}DATA;

//���ṹ�壻
typedef struct _Check
{
	int ZCALL_count;
	int CALLED_count; 
	int Time_Sub; 
	int Incomp;
}Check;

//�ļ�����ʱ��ṹ�壻
typedef struct _FileAndTime
{
	int year;
	int mon;
	int day;
	int hour;
	int min;
	int sec;
}FileAndTime;

//��ʾ�����棻
void UserInterface()
{
	int i, j;
	int k = 0;
	char s[31] = "��ӭʹ��S1240���ݽ������ɼ�ϵͳ";
	char s1[21] = "��ѡ��������Ҫ�Ĳ���:";
	char s2[10] = "0:����ת��";
	char s3[10] = "1:��������";
	char s4[10] = "2:����У��";
	char s5[10] = "3:��־����";
	char s6[6] = "4:�˳�";
	//	int f = 0;
	///printf("********************��ӭʹ��S1240���ݽ������ɼ�ϵͳ********************\n");  //31+40
	for (i = 0; i < 10; i++)                      //���ƣ�
	{
		//-------------------------------------��һ�д�ӡ"��ӭʹ��S1240���ݽ������ɼ�ϵͳ"��---------------------------------------------------------;
		if (i == 0)
		{
			for (j = 0; j < 71; j++)
			{
				if (j < 20)
				{
					putchar('*');                 //��ӡ*�� ��
				}
				else if (j >= 20 && j <= 50)
				{

					if (k < 31)
					{
						putchar(s[k]);            
						k++;
					}
				}
				else
				{
					putchar('*');            //��ӡ*�ţ�
				}
				//	printf("\n");
			}
			printf("\n");
		}
		//-------------------------------------�����д�ӡ "��ѡ��������Ҫ�Ĳ���:"---------------------------------------------------------;
		else if (i == 3)
		{
			k = 0;
			for (j = 0; j < 71; j++)             //ÿ�еĵ�һ��Ԫ�غ����һ��Ԫ�ض�Ϊ*�ţ�����Ϊ�ո�
			{
				if (j == 0 || j == 70)
				{
					putchar('*');
				}
				else if (j < 20)
				{
					putchar(' ');
				}
				else  if (j >= 20 && j <= 40 && k < 21)
				{
					putchar(s1[k]);             
					k++;
				}
				else
				{
					putchar(' ');
				}
			}
			puts("");
		}
		//----------------------------------------------------�����д�ӡ "0:����ת��";--------------------------------------------------
		else if (i==4)
		{
			k = 0;
			for (j = 0; j < 71; j++)             //ÿ�еĵ�һ��Ԫ�غ����һ��Ԫ�ض�Ϊ*�ţ�����Ϊ�ո�
			{
				if (j == 0 || j == 70)
				{
					putchar('*');
				}
				else if (j < 20)
				{
					putchar(' ');
				}
				else  if (j >= 20 && j < 30 && k < 10)
				{
					putchar(s2[k]);
					k++;
				}
				else
				{
					putchar(' ');
				}
			}
			puts("");


		}
		//----------------------------------------------------������ ��ӡ�� "1:��������";-----------------------------------------------��
		else if (i == 5)
		{
			k = 0;
			for (j = 0; j < 71; j++)             //ÿ�еĵ�һ��Ԫ�غ����һ��Ԫ�ض�Ϊ*�ţ�����Ϊ�ո�
			{
				if (j == 0 || j == 70)
				{
					putchar('*');
				}
				else if (j < 20)
				{
					putchar(' ');
				}
				else  if (j >= 20 && j < 30 && k < 10)
				{
					putchar(s3[k]);               
					k++;
				}
				else
				{
					putchar(' ');
				}
			}
			puts("");
		}
		//----------------------------------------------------������-��ӡ��"2:����У��"----------------------------------------------��
		else if (i == 6)
		{
			k = 0;
			for (j = 0; j < 71; j++)             //ÿ�еĵ�һ��Ԫ�غ����һ��Ԫ�ض�Ϊ*�ţ�����Ϊ�ո�
			{
				if (j == 0 || j == 70)
				{
					putchar('*');
				}
				else if (j < 20)
				{
					putchar(' ');
				}
				else  if (j >= 20 && j < 30 && k < 10)
				{
					putchar(s4[k]);                
					k++;
				}
				else
				{
					putchar(' ');
				}
			}
			puts("");
		}
		//----------------------------------------------------�ڰ��д�ӡ  "3:��־����"----------------------------------------------
		else if (i == 7)
		{
			k = 0;
			for (j = 0; j < 71; j++)             //ÿ�еĵ�һ��Ԫ�غ����һ��Ԫ�ض�Ϊ*�ţ�����Ϊ�ո�
			{
				if (j == 0 || j == 70)
				{
					putchar('*');
				}
				else if (j < 20)
				{
					putchar(' ');
				}
				else  if (j >= 20 && j < 26 && k < 6)
				{
					putchar(s5[k]);
					k++;
				}
				else
				{
					putchar(' ');
				}
			}
			puts("");

		}
		//----------------------------------------------------�ھ��д�ӡ "4:�˳�" -----------------------------------------------��
		else if (i == 8)
		{
			k = 0;
			for (j = 0; j < 71; j++)             //ÿ�еĵ�һ��Ԫ�غ����һ��Ԫ�ض�Ϊ*�ţ�����Ϊ�ո�
			{
				if (j == 0 || j == 70)
				{
					putchar('*');
				}
				else if (j < 20)
				{
					putchar(' ');
				}
				else  if (j >= 20 && j < 26 && k < 6)
				{
					putchar(s6[k]);                
					k++;
				}
				else
				{
					putchar(' ');
				}
			}
			puts("");
		}
		//----------------------------------------------------��ʮ��-----------------------------------------------��
		else if (i == 9)
		{
			for (j = 0; j < 71; j++)
			{
				putchar('*');
			}
			puts("");
		}
		//----------------------------------------------------������-----------------------------------------------��
		else
		{
			for (j = 0; j < 71; j++)             //ÿ�еĵ�һ��Ԫ�غ����һ��Ԫ�ض�Ϊ*�ţ�����Ϊ�ո�
			{
				if (j == 0 || j == 70)
				{
					putchar('*');
				}
				else
				{
					putchar(' ');
				}
			}
			puts("");
		}
	}
	//printf("********************��ӭʹ��S1240���ݽ������ɼ�ϵͳ********************\n");
	puts("");
}

//��ʾ��һ���ӽ��棻
void UserInterface1()
{
	int i, j;
	int k = 0;
	char s[31] = "��ӭʹ��S1240���ݽ������ɼ�ϵͳ";
	char s1[21] = "��ѡ��������Ҫ�Ĳ���:";
	char s2[] = "0:��ʾ�ɲ����ļ�";
	char s3[] = "1:������һ���˵�";
	int len1 = strlen(s2);
	int len2 = strlen(s3);
	for (i = 0; i < 7; i++)                      //���ƣ�
	{
		//-------------------------------------��һ��---------------------------------------------------------;
		if (i == 0)
		{
			for (j = 0; j < 71; j++)
			{
				if (j < 20)
				{
					putchar('*');                 //��ӡ*�� ��
				}
				else if (j >= 20 && j <= 50)
				{

					if (k < 31)
					{
						putchar(s[k]);            //��ӡ"��ӭʹ��S1240���ݽ������ɼ�ϵͳ"��
						k++;
					}
				}
				else
				{
					putchar('*');            //��ӡ*�ţ�
				}
				//	printf("\n");
			}
			printf("\n");
		}
		//-------------------------------------������---------------------------------------------------------;
		else if (i == 2)
		{
			k = 0;
			for (j = 0; j < 71; j++)             //ÿ�еĵ�һ��Ԫ�غ����һ��Ԫ�ض�Ϊ*�ţ�����Ϊ�ո�
			{
				if (j == 0 || j == 70)
				{
					putchar('*');
				}
				else if (j < 20)
				{
					putchar(' ');
				}
				else  if (j >= 20 && j <= 40 && k < 21)
				{
					putchar(s1[k]);             //��ӡ "��ѡ��������Ҫ�Ĳ���:"
					k++;
				}
				else
				{
					putchar(' ');
				}
			}
			puts("");
		}
		//----------------------------------------------------������-----------------------------------------------��
		else if (i == 4)
		{
			k = 0;
			for (j = 0; j < 71; j++)             //ÿ�еĵ�һ��Ԫ�غ����һ��Ԫ�ض�Ϊ*�ţ�����Ϊ�ո�
			{
				if (j == 0 || j == 70)
				{
					putchar('*');
				}
				else if (j < 20)
				{
					putchar(' ');
				}
				else  if (j >= 20 && j <20 + len1 && k <len1)
				{
					putchar(s2[k]);                 //��ӡ��  "0:����ת��";
					k++;
				}
				else
				{
					putchar(' ');
				}
			}
			puts("");
		}
		//----------------------------------------------------������-----------------------------------------------��
		else if (i == 5)
		{
			k = 0;
			for (j = 0; j < 71; j++)             //ÿ�еĵ�һ��Ԫ�غ����һ��Ԫ�ض�Ϊ*�ţ�����Ϊ�ո�
			{
				if (j == 0 || j == 70)
				{
					putchar('*');
				}
				else if (j < 20)
				{
					putchar(' ');
				}
				else  if (j >= 20 && j <20 + len2 && k <len2)
				{
					putchar(s3[k]);                 //��ӡ��  "0:����ת��";
					k++;
				}
				else
				{
					putchar(' ');
				}
			}
			puts("");
		}
		else if (i == 6)
		{
			for (j = 0; j < 71; j++)
			{
				putchar('*');
			}
			puts("");
		}
		//----------------------------------------------------������-----------------------------------------------��
		else
		{
			for (j = 0; j < 71; j++)             //ÿ�еĵ�һ��Ԫ�غ����һ��Ԫ�ض�Ϊ*�ţ�����Ϊ�ո�
			{
				if (j == 0 || j == 70)
				{
					putchar('*');
				}
				else
				{
					putchar(' ');
				}
			}
			puts("");
		}
	}
	//printf("********************��ӭʹ��S1240���ݽ������ɼ�ϵͳ********************\n");
	puts("");
}

//��ʾ��������
void ProgressBar(char FileName[],char s[])
{
	int i;
	printf(FileName);
	for (i = 1; i <= 100; i++)
	{
		if (i <= 9)
		{
			printf("%d%%", i);
			Sleep(100);
			printf("\b\b");
		
		}
		else if (i < 100)
		{
			printf("%d%%", i);
			Sleep(100);
			printf("\b\b\b");
		
		}
		else
		{
			printf("%d%%", i);
	
			break;
		}
	}
	printf("...\n");
	printf(s);
}

//��ȡ��ǰʱ�䣻
void GetTime(FILE* fp)
{
	//FileAndTime ft;      //�����ļ�����ʱ��ṹ�壻
	///char *wday[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };/*ָ���ַ�����*/
	time_t t;
	struct tm *p;
	t = time(NULL);/*��ȡ��1970��1��1����ʱ�����ڵ����������浽����t��*/
	p = localtime(&t); /*����t��ֵת��Ϊʵ������ʱ��ı�ʾ��ʽ*/
	fprintf(fp,"%d/%02d/%02d", (1900 + p->tm_year), (1 + p->tm_mon), p->tm_mday);
	//printf(" %s ", wday[p->tm_wday]);
	fprintf(fp,"%c%c%02d:%02d:%02d",' ',' ', p->tm_hour, p->tm_min, p->tm_sec);
	//return ft;
}

//ת�����ƹ��̣�
void TransCode(char* Code, FILE* FilePoint, int len)
{
	char ch, ch1, ch2;
	int temp,temp1, temp2;
	int i = 0,j = 0;
	while (j < len / 2)
	{
			ch = fgetc(FilePoint);
			temp = ch >> 4;
			temp1 = temp & 15;
			temp = ch & 15;
			temp2 = temp;

			if (temp1 > 9 || temp1 < 0)          //ȡBCD���еĳ�ǰһ������
			{
				Code[i] = ' ';
			}
			else
			{
				Code[i] = temp1 + 48;
			}
			i++;

			if (temp2 > 9 || temp2 < 0)       //ȡBCD���еĳ���һ������
			{
				Code[i] = ' ';
			}
			else
			{
				Code[i] = temp2 + 48;
			}
			i++;

			j++;
		}
}

//���ṹ�帳ֵȻ��д��Data\ASC_Data�ļ����У�
void Write_DATA_ASC()
{
	DATA BSD2_DATA;
	int i, j;
	FILE* BSD2;
	FILE* BSD3, *ASC2;
	char Code[6] = "";
	BSD3 = fopen("C�׶���Ŀ\\Data\\Raw_Data\\LD960906.BS3", "rb");   //��BSD3�ļ���
	{
		for (int k = 0; k < 3; k++)
		{
			BSD2_DATA.space1[k] = ' ';
			BSD2_DATA.space2[k] = ' ';
			BSD2_DATA.space3[k] = ' ';
			BSD2_DATA.space4[k] = ' ';
			BSD2_DATA.space5[k] = ' ';
			BSD2_DATA.space6[k] = ' ';
			BSD2_DATA.space7[k] = ' ';
			BSD2_DATA.space8[k] = ' ';
			BSD2_DATA.space9[k] = ' ';
			BSD2_DATA.space10[k] = ' ';
		}
	}
	if (BSD3 == NULL)
	{
		printf("�ļ������ڣ���\n");
		exit(0);
	}
	else
	{
		fseek(BSD3, 54, SEEK_CUR);
		fread(Code, 6, 1, BSD3);
		fclose(BSD3);
	}
	BSD2_DATA_BLOCKS = atoi(Code);

	BSD2 = fopen("C�׶���Ŀ/Data/Raw_Data/LD960906.BS2", "rb");
	ASC2 = fopen("C�׶���Ŀ/Data/ASC_Data/LD960906AS2.txt", "wb");
	for (i = 0; i < BSD2_DATA_BLOCKS; i++)
	{
		fseek(BSD2, 4, SEEK_CUR);
		for (j = 0; j < 68; j++)
		{
			int end;
			end = sizeof(BSD2_DATA.flag1) / sizeof(BSD2_DATA.flag1[0]);            //�ѱ�־1ת������ṹ���Ա����flag1��;
			TransCode(BSD2_DATA.flag1, BSD2, end);          //ת�룻
		
			end = sizeof(BSD2_DATA.ZCALL) / sizeof(BSD2_DATA.ZCALL[0]); 
			TransCode(BSD2_DATA.ZCALL, BSD2, end);

			end = sizeof(BSD2_DATA.flag2) / sizeof(BSD2_DATA.flag2[0]);
			TransCode(BSD2_DATA.flag2, BSD2, end);

			end = sizeof(BSD2_DATA.CALLED) / sizeof(BSD2_DATA.CALLED[0]);
			TransCode(BSD2_DATA.CALLED, BSD2, end);

		    end = sizeof(BSD2_DATA.START_TIME) / sizeof(BSD2_DATA.START_TIME[0]);
			TransCode(BSD2_DATA.START_TIME, BSD2, end);

			end = sizeof(BSD2_DATA.END_TIME) / sizeof(BSD2_DATA.END_TIME[0]);
			TransCode(BSD2_DATA.END_TIME, BSD2, end);

			end = sizeof(BSD2_DATA.COM_DATA) / sizeof(BSD2_DATA.COM_DATA[0]);
			TransCode(BSD2_DATA.COM_DATA, BSD2, end);

			end = sizeof(BSD2_DATA.COM_TIMT_LENGTH) / sizeof(BSD2_DATA.COM_TIMT_LENGTH[0]);
			TransCode(BSD2_DATA.COM_TIMT_LENGTH, BSD2, end);

			end = sizeof(BSD2_DATA.flag3) / sizeof(BSD2_DATA.flag3[0]);
			TransCode(BSD2_DATA.flag3, BSD2, end);

			end = sizeof(BSD2_DATA.OUT_MID_CON) / sizeof(BSD2_DATA.OUT_MID_CON[0]);
			TransCode(BSD2_DATA.OUT_MID_CON, BSD2, end);

			fwrite(&BSD2_DATA, sizeof(DATA), 1, ASC2);
			fputc('\r', ASC2);
			fputc('\n', ASC2);
		}
		fseek(BSD2, 4, SEEK_CUR);//ת�룻
	}
	fclose(ASC2);
	fclose(BSD2);
	
	ProgressBar("����ת����...�Ѽ���  ", "ת��ɹ�!");
	Sleep(1000);
	getchar();
}

//Write_DATA_ASC()��������Ҫд����������кţ����кţ�ͨ��ʱ�����������ݽ��м�����
Check Judge_Figure_Num(DATA DATA_Check_s, FILE* Check_s)
{
	Check check;
	int ZCALL_count = 0, CALLED_count=0,Time_Sub=0,Incomp=0;
	int i = 0,k=0;
	int x = 0,y = 0;
	while (i<sizeof(DATA_Check_s.ZCALL))   //�������к���λ����
	{
		if (DATA_Check_s.ZCALL[i] >= '0'&&DATA_Check_s.ZCALL[i] <= '9')
		{
			ZCALL_count++;
			check.ZCALL_count = ZCALL_count;
		
		}
		i++;
	}
	i = 0;
	while (i<sizeof(DATA_Check_s.CALLED))   //���㱻�к���λ����
	{
		if (DATA_Check_s.CALLED[i] >= '0'&&DATA_Check_s.ZCALL[i] <= '9')
		{
			CALLED_count++;
			check.CALLED_count = CALLED_count;
		}
		i++;
	}
	
	x = atol(DATA_Check_s.START_TIME), y = atol(DATA_Check_s.END_TIME);
	if (y>=x)      //ʱ��
	{
		Time_Sub = 1;
	}
	else
	{
		Time_Sub = 0;
	}
	check.Time_Sub = Time_Sub;
	if (DATA_Check_s.flag1[0] !='0')        //�������ݣ�
	{
		Incomp = 1;
	}
	else
	{
		Incomp = 0;
	}
	check.Incomp = Incomp;
	return check;
}

//DATA_Check()��������Ҫд����������кţ����кţ�ͨ��ʱ�����������ݽ����жϣ�����Ҫ��д�룬���򲻽���д�������
void DATA_Check()
{
	int i, j;
	FILE* DATA_Check_fp;
	FILE* ASC2_fp;
	DATA DATA_Check_s;
	Check  check;
	ASC2_fp = fopen("C�׶���Ŀ/Data/ASC_Data/LD960906AS2.txt", "rb");
	DATA_Check_fp = fopen("C�׶���Ŀ/Data/Check_Data/Check_data_ASC.txt", "wb");
	if (ASC2_fp == NULL)     //��ASC2�ļ��У�
	{
		printf("�ļ������ڣ���\n");
		exit(0);
	}
	if (DATA_Check_fp == NULL)    //��DATA_Check_fp�ļ��У�
	{
		printf("�ļ������ڣ���\n");
		exit(0);
	}
	else
	{
		for (i = 0; i < BSD2_DATA_BLOCKS; i++)
		{
			for (j = 0; j < 68; j++)
			{

				fread(&DATA_Check_s, sizeof(DATA), 1, ASC2_fp);
				fgetc(ASC2_fp);
				fgetc(ASC2_fp);
				check = Judge_Figure_Num(DATA_Check_s, ASC2_fp);
				if ((check.ZCALL_count>=7) && (check.CALLED_count>=3)&& (check.Time_Sub == 1 ))
				{
					fwrite(&DATA_Check_s, sizeof(DATA), 1,DATA_Check_fp);    
					fputc('\r', DATA_Check_fp);
					fputc('\n', DATA_Check_fp);
				}		
				else
				{
					continue;
				}
			}
		}
		fclose(DATA_Check_fp);
		fclose(ASC2_fp);
	}
	ProgressBar("����У����...�Ѽ���  ", "У��ɹ�!");
	Sleep(1000);
	getchar();

}

//��������
void DATA_Sort()
{
	int i, j;
	DATA Sort_1[390], Sort_2;
	FILE* STD_Sort;
	FILE*  Check_data_ASC;
	Check_data_ASC = fopen("C�׶���Ŀ/Data/Check_Data/Check_data_ASC.txt","rb");
    STD_Sort = fopen("C�׶���Ŀ/Data/STD_Data/Sort.txt", "wb");
	if (Check_data_ASC==NULL)        //���ļ�Data/Check_Data/Check_data_ASC.tx��
	{
		printf("�ļ������ڣ���\n");
		exit(0);
	}
	if (STD_Sort == NULL)    //��Sort.txt�ļ���
	{
		printf("�ļ������ڣ���\n");
		exit(0);
	}
	else
	{
		for (i = 0; i < 390; i++)   //�ܹ�390��������һ��һ������Ȼ��д��Check_data_ASC�ṹ���У�
		{
			fread(&Sort_1[i], sizeof(Sort_1[0]), 1, Check_data_ASC);
			fgetc(Check_data_ASC);
		    fgetc(Check_data_ASC);

		}
		//�Խṹ���е�ÿ����������ð������
		for (i = 0; i < 390 - 1; i++)
		{
			for (j = 0; j < 390 - i - 1; j++)
			{

				if (atol((Sort_1[j]).ZCALL)>atol((Sort_1[j + 1]).ZCALL))
				{
					Sort_2 = Sort_1[j];
					Sort_1[j] = Sort_1[j + 1];
					Sort_1[j + 1] = Sort_2;
				}
				else if (atol((Sort_1[j]).ZCALL)==atol((Sort_1[j + 1]).ZCALL))
				{
					if (atoi(Sort_1[j].COM_DATA)>atoi(Sort_1[j + 1].COM_DATA))
					{
						Sort_2 = Sort_1[j];
						Sort_1[j] = Sort_1[j + 1];
						Sort_1[j + 1] = Sort_2;
					}
					else if (atoi(Sort_1[j].COM_DATA)==atoi(Sort_1[j + 1].COM_DATA))
					{
						if (atoi(Sort_1[j].START_TIME) > atoi(Sort_1[j + 1].START_TIME))
						{
							Sort_2 = Sort_1[j];
							Sort_1[j] = Sort_1[j + 1];
							Sort_1[j + 1] = Sort_2;
						}
					}
				}
			}
		}
     // ��ÿһ������д��STD_Sort�ļ��У�
			for (j = 0; j < 390; j++)
			{
				
				fwrite(&Sort_1[j], sizeof(DATA), 1, STD_Sort);
		
				fputc('\r', STD_Sort);
				fputc('\n', STD_Sort);
			}
		fclose(STD_Sort);
		fclose(Check_data_ASC);
	}
	ProgressBar("����������...�Ѽ���  ", "��������ɹ�!");
	Sleep(1000);
	getchar();
}

//д����־��
void Write_Log(char fn[],int menu)
{
	FILE* DATA_LOG;
	DATA_LOG = fopen("C�׶���Ŀ/Data/LOG/Log.txt", "ab");
	if (DATA_LOG == NULL)
	{
		printf("�ļ������ڣ�����");
		exit(0);
	}
	else
	{
		switch (menu)
		{
		case 0:
		{
			fputs(fn,DATA_LOG);
			fputc('\t', DATA_LOG);
			GetTime(DATA_LOG);
			fputc('\r',DATA_LOG);
			fputc('\n', DATA_LOG);
		   ;
		}break;
		case 1:
		{
			
			fputs(fn, DATA_LOG);
			fputc('\t', DATA_LOG);
			GetTime(DATA_LOG);	
			fputc('\n', DATA_LOG);
			fputc('\r', DATA_LOG);

		}break;
		case 2:
		{
			
			fputs(fn, DATA_LOG);
			fputc('\t', DATA_LOG);
			GetTime(DATA_LOG);
			fputc('\r', DATA_LOG);
			fputc('\n', DATA_LOG);
			
		}
		default:
			break;
		}
	}
	fclose(DATA_LOG);
}

//����־��
void Read_Log()
{
	char ch;
	FILE* Read_Log;
	Read_Log = fopen("C�׶���Ŀ\\Data\\LOG\\Log.txt","rb");
	ProgressBar("��ȡ��־��...�Ѽ���  ","");
	Sleep(1000);
	if (Read_Log == NULL)
	{
		printf("�ļ������ڣ���\n");
		exit(0);
	}
	else
	{
		puts("");
		while (!feof(Read_Log))
		{
			ch=fgetc(Read_Log);
			putchar(ch);
		}
		
		puts("\n����־��ϣ���");
		getchar();
		Sleep(1000);
	}
}
int main(void)
{
	char SelctedFileName[100] = "";
	char ch;   //����ѡ���Ƿ�������в�����
	//int i;         //����ȥ�ַ����е� 
	int menu;//ѡ��˵���
	int menu1;// ѡ���Ӳ˵���
	FileAndTime ft;
	FILE* Log;
	UserInterface();
	scanf_s("%d",&menu);
	while (menu != 4)
	{
		switch (menu)
		{
		case 0:
		{
			system("cls");
			UserInterface1();
			scanf_s("%d", &menu1);
			if (menu1 == 0)   //��ʾ�ɲ����ļ���
			{
				system("cls");
				puts("�ɲ������ļ��У�");
				system("dir /b .\\C�׶���Ŀ\\Data\\Raw_Data");
				puts("������Ҫ�������ļ�����");
				fflush(stdin);
				gets(SelctedFileName);
				if (strcmp(SelctedFileName ,"LD960906.BS2")==0)
				{
					Write_DATA_ASC();
					Write_Log(SelctedFileName, menu);
				}
				else
				{
					puts("���������д������������룡��");
					getchar();
					system("cls");
					UserInterface1();
					scanf_s("%d", &menu1);
					fflush(stdin);
					puts("������ Y/y--��,N/n--��");
					ch = getchar();
					if (ch == 'N' || ch == 'n')
						return;
				}

			}
			else
			{
				system("cls");
				UserInterface();
				scanf_s("%d", &menu);
				
			}
		}break;

		case 1:
		{
			system("cls");
			UserInterface1();
			scanf_s("%d", &menu1);
			if (menu1 == 0)   //��ʾ�ɲ����ļ���
			{
				
				system("cls");
				puts("�ɲ������ļ��У�");
				system("dir /b .\\C�׶���Ŀ\\Data\\STD_Data");
				puts("������Ҫ�������ļ�����");
				fflush(stdin);
				gets(SelctedFileName);
				if (strcmp(SelctedFileName, "Sort.txt") == 0)
				{
					DATA_Sort();
					Write_Log(SelctedFileName, menu);
				}
				else
				{
					puts("���������д������������룡��");
					getchar();
					system("cls");
					UserInterface1();
					scanf_s("%d", &menu1);
					fflush(stdin);
					puts("������ Y/y--��,N/n--��");
					ch = getchar();
					if (ch == 'N' || ch == 'n')
						return;
				}
			}
			else
			{
				system("cls");
				UserInterface();
				scanf_s("%d", &menu);
			}
		}break;

		case 2:
		{
			system("cls");
			UserInterface1();
			scanf_s("%d", &menu1);
			if (menu1 == 0)   //��ʾ�ɲ����ļ���
			{
				system("cls");
				puts("�ɲ������ļ��У�");
				system("dir /b .\\C�׶���Ŀ\\Data\\Check_Data");
				puts("������Ҫ�������ļ�����");
				fflush(stdin);
				gets(SelctedFileName);
				if (strcmp(SelctedFileName, "Check_data_ASC.txt")==0)
				{
					DATA_Check();
					Write_Log(SelctedFileName, menu);
				}
				else
				{
					puts("���������д������������룡��");
					getchar();
					system("cls");
					UserInterface1();
					scanf_s("%d", &menu1);
					fflush(stdin);
					puts("������ Y/y--��,N/n--��");
					ch = getchar();
					if (ch == 'N' || ch == 'n')
						return;
				}
			}
			else
			{
				system("cls");
				UserInterface();
				scanf_s("%d", &menu);
				
			}
		}break;

		case 3:
		{
			system("cls");
			UserInterface1();
			scanf_s("%d", &menu1);
			if (menu1 == 0)   //��ʾ�ɲ����ļ���
			{
				system("cls");
				puts("�ɲ������ļ��У�");
				system("dir /b .\\C�׶���Ŀ\\Data\\LOG");
				puts("������Ҫ�������ļ�����");
				fflush(stdin);
				gets(SelctedFileName);
				if (strcmp(SelctedFileName, "Log.txt") == 0)
				{
					Read_Log();
					fflush(stdin);
				
					Log = fopen("C�׶���Ŀ\\Data\\LOG\\Log.txt", "wb");
					if (Log == NULL)
					{
						printf("�ļ������ڣ���\n");
						exit(0);
					}
				}
				else
				{
					puts("���������д������������룡��");
					getchar();
					system("cls");
					UserInterface1();
					scanf_s("%d", &menu1);
					fflush(stdin);
					puts("������ Y/y--��,N/n--��");
					ch = getchar();
					if (ch == 'N' || ch == 'n')
						return;

				}
				
			}
			else
			{
				system("cls");
				UserInterface();
				scanf_s("%d", &menu);
			}
		}break;
		default:		
			return;
		}
	}
	return 0;
}
