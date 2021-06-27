#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#define MaxLen  512
#define DEBUGPRINTTOSRCEEN

#ifndef CHAR_TYPEDEFINE
#define CHAR_TYPEDEFINE
typedef char CHAR;
#endif

#ifndef UCHAR_TYPEDEFINE
#define UCHAR_TYPEDEFINE
typedef unsigned char UCHAR;
#endif

#ifndef VOID_TYPEDEFINE
#define VOID_TYPEDEFINE
typedef void VOID;
#endif

#ifndef WORD_TYPEDEFINE
#define WORD_TYPEDEFINE
typedef unsigned short int WORD;
#endif

#ifndef BOOL_ENUM
#define BOOL_ENUM
typedef enum {FALSE = 0, TRUE = 1}BOOL;
#endif

#define Maxdata 200
#define Maxline 512

// HJ 阵地优化应用参数
typedef struct TAP_HJ_CONTRL_REAL_DATA_MSG
{
	// ACU参数
	unsigned char				 IMUAB;
	double                      acu_control_parm;	    // 伺服响应参数 低通滤波器
	double                      acu_control_parm_up_k;	// 伺服响应参数 低通滤波器步进
	double                      acu_control_parm_up;	// 伺服响应参数 低通滤波器上限
	double                      acu_control_parm_V;	    // 伺服控制步进上限
	// 滤波参数
	double                      A_filter;
	double                      B_filter;
	double                      nTrackNum;

	// 波门参数
	double                     faiBomen;            	// 粗相关波门信息
	double                     eleBomen;

	double                     fm_faiBomen;	            // 通道间判断波门信息
	double                     fm_eleBomen;

	unsigned int               MemoryAsureTime; // 记忆跟踪确定时间
	unsigned int               FMToDbfTime;
	unsigned int               MemoryTime;

	// 目标确认参数
	unsigned int               N_Parm;
	unsigned int               M_Parm;
	double                     UBomen; // U空间关联门限
	double                     VBomen; // V空间关联门限
	double                     AmpAsure;
	double                     AmpUpDown;

	double                     ACUModifyParm;
	unsigned int               DigitDeltTime; // 数引无效时长
	double                     AziSytemError; // 方位系统误差
	double                     EleSytemError; // 俯仰系统误差
} TAP_HJ_CONTRL_REAL_DATA_MSG;

int atoi(char s[])
{
    int i;
    int n=0;
    for(i=0;s[i]>='0'&&s[i]<=9;++i)
    {

        n = 10*n + (s[i] - '0');
    }
    return n;
}

void showstruct(const TAP_HJ_CONTRL_REAL_DATA_MSG * STR)
{
    printf("ACU参数\n");
    printf("STR->IMUAB = %hhd \n", STR->IMUAB);
    printf("STR->acu_control_parm = %lf \n", STR->acu_control_parm );
    printf("STR->acu_control_parm_up_k = %lf \n", STR->acu_control_parm_up_k);
    printf("STR->acu_control_parm_up = %lf \n", STR->acu_control_parm_up);
    printf("STR->acu_control_parm_V = %lf \n", STR->acu_control_parm_V);

    printf("滤波参数\n");
    printf("STR->A_filter = %lf \n", STR->A_filter);
    printf("STR->B_filter = %lf \n", STR->B_filter);
    printf("STR->nTrackNum = %lf \n", STR->nTrackNum);

    printf("玻门参数\n");
    printf("STR->faiBomen = %lf \n", STR->faiBomen);
    printf("STR->eleBomen = %lf \n", STR->eleBomen);

    printf("STR->fm_faiBomen = %lf \n", STR->fm_faiBomen);
    printf("STR->fm_eleBomen = %lf \n", STR->fm_eleBomen);

    printf("STR->MemoryAsureTime = %u \n", STR->MemoryAsureTime);
    printf("STR->FMToDbfTime = %u \n", STR->FMToDbfTime);
    printf("STR->MemoryTime = %u \n", STR->MemoryTime);


    printf("目标确认参数\n");
    printf("STR->N_Parm = %u \n", STR->N_Parm);
    printf("STR->M_Parm = %u \n", STR->M_Parm);
    printf("STR->UBomen = %lf \n", STR->UBomen);
    printf("STR->VBomen = %lf \n", STR->VBomen);
    printf("STR->AmpAsure = %lf \n", STR->AmpAsure);
    printf("STR->AmpUpDown = %lf \n", STR->AmpUpDown);

    printf("STR->ACUModifyParm = %lf \n", STR->ACUModifyParm);
    printf("STR->DigitDeltTime = %u \n", STR->DigitDeltTime);
    printf("STR->AziSytemError = %lf \n", STR->AziSytemError);
    printf("STR->EleSytemError = %lf \n", STR->EleSytemError);
}

char *s_gets(char *st, int n, FILE *fp)
{
    char *ret_val;
    int i = 0;
    ret_val = fgets(st, n, fp);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
        {
            i++;
        }

        if (st[i] == '\n')
        {
            st[i] = '\0';
        }
        else
        {
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }
    return ret_val;
}

VOID vExtractKeyline(CHAR *line, CHAR *keyline)
{
    int i = 0,j = 0;
    WORD Len = 0;
    CHAR Temp[Maxline];

    /* 去除行首空白符 */
    while (line[i]==' ')
        i++;
    while (line[i] != '\n')
    {
        Temp[j++] = line[i];
        i++;
    }
    Temp[j] = '\0';

    /* 去除行尾空白符 */
    Len = strlen(Temp);
    while(Temp[Len-1] == ' ')
        Len--;

    j=0;
    while(j<Len)
    {
        keyline[j]=Temp[j];
        j++;
    }
    keyline[j] = '\0';

}

BOOL bExtractKeyvalue(CHAR *line,CHAR *linename,UCHAR Nofv, CHAR keyvalue[][Maxdata])
{
    UCHAR i=0, j=0,num=0;
    UCHAR EndFlag=0;
    BOOL Result = TRUE;

    /*去除行首空白字符*/
    while(line[i]==' ')
        i++;

    while(!EndFlag)
    {
        while((line[i]!=' ')&&(line[i]!='\0'))
        {
            keyvalue[num][j++]=line[i];
            i++;

        }
        /*到行末 跳出循环*/
        if(line[i]=='\0')
            EndFlag = 1;

        keyvalue[num][j]='\0';

        j=0;
        while(line[i]==' ')
            i++;

        num++;
    }

    if( (Nofv != num) && (Nofv != 0xff) )
    {
        Result = FALSE;
#ifdef	DEBUGPRINTTOSRCEEN
        printf("[Warning] The Para num[%d] is not match with given[%d]: %s\n",num,Nofv,linename);
#endif
    }

    return Result;

}

int main(int argc, char *argv[])
{
    TAP_HJ_CONTRL_REAL_DATA_MSG  ReadHJ;

    FILE *Rin = NULL;
    int Result = 1;

    CHAR Filename[Maxline]; //文件名

    CHAR line1[Maxline];  //第一行
    CHAR line2[Maxline];  //第二行
    CHAR Keyline[Maxline];
    CHAR Keyname[Maxdata];//键名
    CHAR Keyvalue[10][Maxdata]; //键值数组 最多一个键名 有10个子项
    UCHAR NofV;//键值个数
    UCHAR IsDone = 0;

    //strcpy(Filename, g_FusRunpath);
    strcpy(Filename, "saveHJParam.txt");
    //strcat(Filename, "outputpara.cfg");
    printf("Filename = %s\n", Filename);
    //vDispDebugMessage(Filename);
    Rin = fopen(Filename,"rb");

    /*配置文件存在*/
    if(Rin != NULL)
    {
        /*获取字段*/
        while(Result)
        {
            if(fgets(line1,Maxline,Rin) == NULL )
                Result=0;

            //抽取键名
            vExtractKeyline(line1,Keyname);
            //抽取键值行
            //vExtractKeyline(line2,Keyline);

            if( strcmp(Keyname,"[ACU parament]")==0)
            {
                printf("%s\n",Keyname);
                NofV=5;
                fscanf(Rin,"%hhd %lf %lf %lf %lf\n",&(ReadHJ.IMUAB), &(ReadHJ.acu_control_parm), &(ReadHJ.acu_control_parm_up_k), &(ReadHJ.acu_control_parm_up),&(ReadHJ.acu_control_parm_V));
                //IsDone = IsDone | 0x01;
            }

            if( strcmp(Keyname,"[filter parament]")==0)
            {
                printf("%s\n",Keyname);
                NofV=3;
                fscanf(Rin,"%lf %lf %lf\n",&(ReadHJ.A_filter),&(ReadHJ.B_filter),&(ReadHJ.nTrackNum));
                //IsDone = IsDone | 0x02;
            }

            if( strcmp(Keyname,"[bomen  parament]")==0)
            {
                printf("%s\n",Keyname);
                NofV=7;
                fscanf(Rin,"%lf %lf %lf %lf %u %u %u\n",&(ReadHJ.faiBomen),&(ReadHJ.eleBomen),&(ReadHJ.fm_faiBomen),&(ReadHJ.fm_eleBomen),&(ReadHJ.MemoryAsureTime),&(ReadHJ.FMToDbfTime),&(ReadHJ.MemoryTime));
                //IsDone = IsDone | 0x10;
            }

            if( strcmp(Keyname,"[target sure parament]")==0)
            {
                printf("%s\n",Keyname);
                NofV=10;
                fscanf(Rin,"%u %u %lf %lf %lf %lf %lf %u %lf %lf\n",&(ReadHJ.N_Parm),&(ReadHJ.M_Parm),&(ReadHJ.UBomen),&(ReadHJ.VBomen),&(ReadHJ.AmpAsure),&(ReadHJ.AmpUpDown),&(ReadHJ.ACUModifyParm),&(ReadHJ.DigitDeltTime),&(ReadHJ.AziSytemError),&(ReadHJ.EleSytemError));
                //IsDone = IsDone | 0x20;
                Result=0;
            }
        }

        /*关闭文件*/
        fclose(Rin);
    }
    else
    {

    }
    printf("\n\n\nRead over.....\n");
    showstruct(&ReadHJ);

    printf("[%s] Config File Path:%s -- %s:%d\n",__func__,Filename,__FILE__,__LINE__);


    return 0;
}


int main(int argc, char *argv[])
{
    TAP_HJ_CONTRL_REAL_DATA_MSG  ReadHJ;

    FILE *Fp = NULL;
    int Result = 1;

    CHAR Filename[Maxline];     //文件名

    CHAR line1[Maxline];        //第一行
    CHAR line2[Maxline];        //第二行
    CHAR Keyline[Maxline];      //键值
    CHAR Keyname[Maxdata];      //键名
    CHAR Keyvalue[10][Maxdata]; //键值数组 最多一个键名 有10个子项
    UCHAR NofV;                 //键值个数
    UCHAR IsDone = 0;

    //strcpy(Filename, g_FusRunpath);
    strcpy(Filename, "saveHJParam.txt");
    //strcat(Filename, "outputpara.cfg");
    printf("Filename = %s\n\n", Filename);
    //vDispDebugMessage(Filename);
    Fp = fopen(Filename,"rb");
    char A[] = "[ACU parament]\0\0\0";//14

    /*配置文件存在*/
    if(Fp != NULL)
    {
        /*获取字段*/
        while(Result)
        {
            if(fgets(line1,Maxline,Fp) == NULL || fgets(line2,Maxline,Fp) == NULL)
            {
                Result=0;
                break;
            }
            fputs(line1,stdout);
            fputs(line2,stdout);
            printf("strlen line1 = %d \n",strlen(line1));
            printf("strlen line2 = %d \n",strlen(line2));


            //抽取键名
            vExtractKeyline(line1,Keyname);

            //抽取键值行
            vExtractKeyline(line2,Keyline);

            printf("Keyname = %s",Keyname);
            printf("keyline = %s",Keyline);

            printf("strlen Keyname = %d \n",strlen(Keyname));
            printf("strlen A = %d \n",strlen(A));//14

            printf("strlen Ketline = %d \n",strlen(Keyline));

            printf("A  = %s\n",A);//14
            printf("sizeof(A) = %d",sizeof(A));
            //printf("[hello world]\n");
            for(int i=0; i<strlen(Keyname); ++i)
            {
                printf("%c ",Keyname[i]);
            }


            if( strcmp(Keyname,"ACU\n") == 0 )
            {
                printf("hello world.................................\n");
            }
            Result = 0;

        }

        /*关闭文件*/
        fclose(Fp);
    }
    else
    {

    }
    printf("\n\n\nRead over.....\n");
    //showstruct(&ReadHJ);

    printf("[%s] Config File Path:%s -- %s:%d\n",__func__,Filename,__FILE__,__LINE__);


}
    char a[] = "hello\n";
    printf("strlen(a) = %d",strlen(a));
    printf("sizeof(a) = %d",sizeof(a));
    return 0;
