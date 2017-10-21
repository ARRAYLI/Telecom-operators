#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int BSD2_DATA_BLOCKS = 0;     //定义全局变量BSD2_DATA_BLOCKS计数6个模块数；
typedef struct space
{
	char space[3];
}Space;

//初始化空格结构体；
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

//话单结构体；
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

//检测结构体；
typedef struct _Check
{
	int ZCALL_count;
	int CALLED_count; 
	int Time_Sub; 
	int Incomp;
}Check;

//文件名和时间结构体；
typedef struct _FileAndTime
{
	int year;
	int mon;
	int day;
	int hour;
	int min;
	int sec;
}FileAndTime;

//显示主界面；
void UserInterface()
{
	int i, j;
	int k = 0;
	char s[31] = "欢迎使用S1240数据交换机采集系统";
	char s1[21] = "请选择您所需要的操作:";
	char s2[10] = "0:码制转换";
	char s3[10] = "1:数据排序";
	char s4[10] = "2:数据校验";
	char s5[10] = "3:日志处理";
	char s6[6] = "4:退出";
	//	int f = 0;
	///printf("********************欢迎使用S1240数据交换机采集系统********************\n");  //31+40
	for (i = 0; i < 10; i++)                      //名称；
	{
		//-------------------------------------第一行打印"欢迎使用S1240数据交换机采集系统"；---------------------------------------------------------;
		if (i == 0)
		{
			for (j = 0; j < 71; j++)
			{
				if (j < 20)
				{
					putchar('*');                 //打印*号 ；
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
					putchar('*');            //打印*号；
				}
				//	printf("\n");
			}
			printf("\n");
		}
		//-------------------------------------第四行打印 "请选择您所需要的操作:"---------------------------------------------------------;
		else if (i == 3)
		{
			k = 0;
			for (j = 0; j < 71; j++)             //每行的第一个元素和最后一个元素都为*号，其余为空格；
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
		//----------------------------------------------------第五行打印 "0:码制转换";--------------------------------------------------
		else if (i==4)
		{
			k = 0;
			for (j = 0; j < 71; j++)             //每行的第一个元素和最后一个元素都为*号，其余为空格；
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
		//----------------------------------------------------第六行 打印： "1:数据排序";-----------------------------------------------；
		else if (i == 5)
		{
			k = 0;
			for (j = 0; j < 71; j++)             //每行的第一个元素和最后一个元素都为*号，其余为空格；
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
		//----------------------------------------------------第七行-打印："2:数据校验"----------------------------------------------；
		else if (i == 6)
		{
			k = 0;
			for (j = 0; j < 71; j++)             //每行的第一个元素和最后一个元素都为*号，其余为空格；
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
		//----------------------------------------------------第八行打印  "3:日志处理"----------------------------------------------
		else if (i == 7)
		{
			k = 0;
			for (j = 0; j < 71; j++)             //每行的第一个元素和最后一个元素都为*号，其余为空格；
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
		//----------------------------------------------------第九行打印 "4:退出" -----------------------------------------------；
		else if (i == 8)
		{
			k = 0;
			for (j = 0; j < 71; j++)             //每行的第一个元素和最后一个元素都为*号，其余为空格；
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
		//----------------------------------------------------第十行-----------------------------------------------；
		else if (i == 9)
		{
			for (j = 0; j < 71; j++)
			{
				putchar('*');
			}
			puts("");
		}
		//----------------------------------------------------其他行-----------------------------------------------；
		else
		{
			for (j = 0; j < 71; j++)             //每行的第一个元素和最后一个元素都为*号，其余为空格；
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
	//printf("********************欢迎使用S1240数据交换机采集系统********************\n");
	puts("");
}

//显示下一级子界面；
void UserInterface1()
{
	int i, j;
	int k = 0;
	char s[31] = "欢迎使用S1240数据交换机采集系统";
	char s1[21] = "请选择您所需要的操作:";
	char s2[] = "0:显示可操作文件";
	char s3[] = "1:返回上一级菜单";
	int len1 = strlen(s2);
	int len2 = strlen(s3);
	for (i = 0; i < 7; i++)                      //名称；
	{
		//-------------------------------------第一行---------------------------------------------------------;
		if (i == 0)
		{
			for (j = 0; j < 71; j++)
			{
				if (j < 20)
				{
					putchar('*');                 //打印*号 ；
				}
				else if (j >= 20 && j <= 50)
				{

					if (k < 31)
					{
						putchar(s[k]);            //打印"欢迎使用S1240数据交换机采集系统"；
						k++;
					}
				}
				else
				{
					putchar('*');            //打印*号；
				}
				//	printf("\n");
			}
			printf("\n");
		}
		//-------------------------------------第三行---------------------------------------------------------;
		else if (i == 2)
		{
			k = 0;
			for (j = 0; j < 71; j++)             //每行的第一个元素和最后一个元素都为*号，其余为空格；
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
					putchar(s1[k]);             //打印 "请选择您所需要的操作:"
					k++;
				}
				else
				{
					putchar(' ');
				}
			}
			puts("");
		}
		//----------------------------------------------------第五行-----------------------------------------------；
		else if (i == 4)
		{
			k = 0;
			for (j = 0; j < 71; j++)             //每行的第一个元素和最后一个元素都为*号，其余为空格；
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
					putchar(s2[k]);                 //打印：  "0:码制转换";
					k++;
				}
				else
				{
					putchar(' ');
				}
			}
			puts("");
		}
		//----------------------------------------------------第六行-----------------------------------------------；
		else if (i == 5)
		{
			k = 0;
			for (j = 0; j < 71; j++)             //每行的第一个元素和最后一个元素都为*号，其余为空格；
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
					putchar(s3[k]);                 //打印：  "0:码制转换";
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
		//----------------------------------------------------其他行-----------------------------------------------；
		else
		{
			for (j = 0; j < 71; j++)             //每行的第一个元素和最后一个元素都为*号，其余为空格；
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
	//printf("********************欢迎使用S1240数据交换机采集系统********************\n");
	puts("");
}

//显示进度条；
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

//获取当前时间；
void GetTime(FILE* fp)
{
	//FileAndTime ft;      //定义文件名和时间结构体；
	///char *wday[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };/*指针字符数组*/
	time_t t;
	struct tm *p;
	t = time(NULL);/*获取从1970年1月1日零时到现在的秒数，保存到变量t中*/
	p = localtime(&t); /*变量t的值转换为实际日期时间的表示格式*/
	fprintf(fp,"%d/%02d/%02d", (1900 + p->tm_year), (1 + p->tm_mon), p->tm_mday);
	//printf(" %s ", wday[p->tm_wday]);
	fprintf(fp,"%c%c%02d:%02d:%02d",' ',' ', p->tm_hour, p->tm_min, p->tm_sec);
	//return ft;
}

//转换码制过程；
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

			if (temp1 > 9 || temp1 < 0)          //取BCD码中的出前一个数；
			{
				Code[i] = ' ';
			}
			else
			{
				Code[i] = temp1 + 48;
			}
			i++;

			if (temp2 > 9 || temp2 < 0)       //取BCD码中的出后一个数；
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

//给结构体赋值然后写入Data\ASC_Data文件夹中；
void Write_DATA_ASC()
{
	DATA BSD2_DATA;
	int i, j;
	FILE* BSD2;
	FILE* BSD3, *ASC2;
	char Code[6] = "";
	BSD3 = fopen("C阶段项目\\Data\\Raw_Data\\LD960906.BS3", "rb");   //打开BSD3文件；
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
		printf("文件不存在！！\n");
		exit(0);
	}
	else
	{
		fseek(BSD3, 54, SEEK_CUR);
		fread(Code, 6, 1, BSD3);
		fclose(BSD3);
	}
	BSD2_DATA_BLOCKS = atoi(Code);

	BSD2 = fopen("C阶段项目/Data/Raw_Data/LD960906.BS2", "rb");
	ASC2 = fopen("C阶段项目/Data/ASC_Data/LD960906AS2.txt", "wb");
	for (i = 0; i < BSD2_DATA_BLOCKS; i++)
	{
		fseek(BSD2, 4, SEEK_CUR);
		for (j = 0; j < 68; j++)
		{
			int end;
			end = sizeof(BSD2_DATA.flag1) / sizeof(BSD2_DATA.flag1[0]);            //把标志1转码后放入结构体成员变量flag1中;
			TransCode(BSD2_DATA.flag1, BSD2, end);          //转码；
		
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
		fseek(BSD2, 4, SEEK_CUR);//转码；
	}
	fclose(ASC2);
	fclose(BSD2);
	
	ProgressBar("码制转换中...已加载  ", "转码成功!");
	Sleep(1000);
	getchar();
}

//Write_DATA_ASC()函数：对要写入的数据主叫号，被叫号，通话时长，残余数据进行计数；
Check Judge_Figure_Num(DATA DATA_Check_s, FILE* Check_s)
{
	Check check;
	int ZCALL_count = 0, CALLED_count=0,Time_Sub=0,Incomp=0;
	int i = 0,k=0;
	int x = 0,y = 0;
	while (i<sizeof(DATA_Check_s.ZCALL))   //计算主叫号码位数；
	{
		if (DATA_Check_s.ZCALL[i] >= '0'&&DATA_Check_s.ZCALL[i] <= '9')
		{
			ZCALL_count++;
			check.ZCALL_count = ZCALL_count;
		
		}
		i++;
	}
	i = 0;
	while (i<sizeof(DATA_Check_s.CALLED))   //计算被叫号码位数；
	{
		if (DATA_Check_s.CALLED[i] >= '0'&&DATA_Check_s.ZCALL[i] <= '9')
		{
			CALLED_count++;
			check.CALLED_count = CALLED_count;
		}
		i++;
	}
	
	x = atol(DATA_Check_s.START_TIME), y = atol(DATA_Check_s.END_TIME);
	if (y>=x)      //时间差；
	{
		Time_Sub = 1;
	}
	else
	{
		Time_Sub = 0;
	}
	check.Time_Sub = Time_Sub;
	if (DATA_Check_s.flag1[0] !='0')        //残余数据；
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

//DATA_Check()函数：对要写入的数据主叫号，被叫号，通话时长，残余数据进行判断，符合要求写入，否则不进行写入操作；
void DATA_Check()
{
	int i, j;
	FILE* DATA_Check_fp;
	FILE* ASC2_fp;
	DATA DATA_Check_s;
	Check  check;
	ASC2_fp = fopen("C阶段项目/Data/ASC_Data/LD960906AS2.txt", "rb");
	DATA_Check_fp = fopen("C阶段项目/Data/Check_Data/Check_data_ASC.txt", "wb");
	if (ASC2_fp == NULL)     //打开ASC2文件夹；
	{
		printf("文件不存在！！\n");
		exit(0);
	}
	if (DATA_Check_fp == NULL)    //打开DATA_Check_fp文件夹；
	{
		printf("文件不存在！！\n");
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
	ProgressBar("数据校验中...已加载  ", "校验成功!");
	Sleep(1000);
	getchar();

}

//数据排序；
void DATA_Sort()
{
	int i, j;
	DATA Sort_1[390], Sort_2;
	FILE* STD_Sort;
	FILE*  Check_data_ASC;
	Check_data_ASC = fopen("C阶段项目/Data/Check_Data/Check_data_ASC.txt","rb");
    STD_Sort = fopen("C阶段项目/Data/STD_Data/Sort.txt", "wb");
	if (Check_data_ASC==NULL)        //打开文件Data/Check_Data/Check_data_ASC.tx；
	{
		printf("文件不存在！！\n");
		exit(0);
	}
	if (STD_Sort == NULL)    //打开Sort.txt文件；
	{
		printf("文件不存在！！\n");
		exit(0);
	}
	else
	{
		for (i = 0; i < 390; i++)   //总共390条话单，一条一条读，然后写入Check_data_ASC结构体中；
		{
			fread(&Sort_1[i], sizeof(Sort_1[0]), 1, Check_data_ASC);
			fgetc(Check_data_ASC);
		    fgetc(Check_data_ASC);

		}
		//对结构体中的每条话单进行冒泡排序；
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
     // 将每一条话单写入STD_Sort文件中；
			for (j = 0; j < 390; j++)
			{
				
				fwrite(&Sort_1[j], sizeof(DATA), 1, STD_Sort);
		
				fputc('\r', STD_Sort);
				fputc('\n', STD_Sort);
			}
		fclose(STD_Sort);
		fclose(Check_data_ASC);
	}
	ProgressBar("数据排序中...已加载  ", "数据排序成功!");
	Sleep(1000);
	getchar();
}

//写入日志；
void Write_Log(char fn[],int menu)
{
	FILE* DATA_LOG;
	DATA_LOG = fopen("C阶段项目/Data/LOG/Log.txt", "ab");
	if (DATA_LOG == NULL)
	{
		printf("文件不存在！！！");
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

//读日志；
void Read_Log()
{
	char ch;
	FILE* Read_Log;
	Read_Log = fopen("C阶段项目\\Data\\LOG\\Log.txt","rb");
	ProgressBar("读取日志中...已加载  ","");
	Sleep(1000);
	if (Read_Log == NULL)
	{
		printf("文件不存在！！\n");
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
		
		puts("\n读日志完毕！！");
		getchar();
		Sleep(1000);
	}
}
int main(void)
{
	char SelctedFileName[100] = "";
	char ch;   //用来选择是否继续进行操作；
	//int i;         //用来去字符串中的 
	int menu;//选择菜单；
	int menu1;// 选择子菜单；
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
			if (menu1 == 0)   //显示可操作文件；
			{
				system("cls");
				puts("可操作的文件有：");
				system("dir /b .\\C阶段项目\\Data\\Raw_Data");
				puts("请输入要操作的文件名：");
				fflush(stdin);
				gets(SelctedFileName);
				if (strcmp(SelctedFileName ,"LD960906.BS2")==0)
				{
					Write_DATA_ASC();
					Write_Log(SelctedFileName, menu);
				}
				else
				{
					puts("您的输入有错，请您重新输入！！");
					getchar();
					system("cls");
					UserInterface1();
					scanf_s("%d", &menu1);
					fflush(stdin);
					puts("请输入 Y/y--是,N/n--否：");
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
			if (menu1 == 0)   //显示可操作文件；
			{
				
				system("cls");
				puts("可操作的文件有：");
				system("dir /b .\\C阶段项目\\Data\\STD_Data");
				puts("请输入要操作的文件名：");
				fflush(stdin);
				gets(SelctedFileName);
				if (strcmp(SelctedFileName, "Sort.txt") == 0)
				{
					DATA_Sort();
					Write_Log(SelctedFileName, menu);
				}
				else
				{
					puts("您的输入有错，请您重新输入！！");
					getchar();
					system("cls");
					UserInterface1();
					scanf_s("%d", &menu1);
					fflush(stdin);
					puts("请输入 Y/y--是,N/n--否：");
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
			if (menu1 == 0)   //显示可操作文件；
			{
				system("cls");
				puts("可操作的文件有：");
				system("dir /b .\\C阶段项目\\Data\\Check_Data");
				puts("请输入要操作的文件名：");
				fflush(stdin);
				gets(SelctedFileName);
				if (strcmp(SelctedFileName, "Check_data_ASC.txt")==0)
				{
					DATA_Check();
					Write_Log(SelctedFileName, menu);
				}
				else
				{
					puts("您的输入有错，请您重新输入！！");
					getchar();
					system("cls");
					UserInterface1();
					scanf_s("%d", &menu1);
					fflush(stdin);
					puts("请输入 Y/y--是,N/n--否：");
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
			if (menu1 == 0)   //显示可操作文件；
			{
				system("cls");
				puts("可操作的文件有：");
				system("dir /b .\\C阶段项目\\Data\\LOG");
				puts("请输入要操作的文件名：");
				fflush(stdin);
				gets(SelctedFileName);
				if (strcmp(SelctedFileName, "Log.txt") == 0)
				{
					Read_Log();
					fflush(stdin);
				
					Log = fopen("C阶段项目\\Data\\LOG\\Log.txt", "wb");
					if (Log == NULL)
					{
						printf("文件不存在！！\n");
						exit(0);
					}
				}
				else
				{
					puts("您的输入有错，请您重新输入！！");
					getchar();
					system("cls");
					UserInterface1();
					scanf_s("%d", &menu1);
					fflush(stdin);
					puts("请输入 Y/y--是,N/n--否：");
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
