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
    printf("STR->EleSytemError = %lf \n\n", STR->EleSytemError);
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
    while (line[i] != '\r')
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

savehj_param(TAP_HJ_CONTRL_REAL_DATA_MSG *example)
{

}

int main(int argc, char *argv[])
{
    TAP_HJ_CONTRL_REAL_DATA_MSG  example;
    //ACU参数
    example.IMUAB = 2;
    example.acu_control_parm = 12.123;
    example.acu_control_parm_up_k = 21.212;
    example.acu_control_parm_up  = 23.23;
    example.acu_control_parm_V = 34.34;

    //滤波参数
    example.A_filter = 45.45;
    example.B_filter = 56.56;
    example.nTrackNum = 67.67;

    //波门参数
    example.faiBomen = 78.78;
    example.eleBomen = 89.89;

    example.fm_faiBomen = 101.11;
    example.fm_eleBomen = 11.111;

    example.MemoryAsureTime = 675;
    example.FMToDbfTime = 203;
    example.MemoryTime = 54;

    //目标确认参数
    example.N_Parm = 303;
    example.M_Parm = 404;
    example.UBomen = 88.888;
    example.VBomen = 99.909;
    example.AmpAsure = 77.777;
    example.AmpUpDown = 333.333;

    example.ACUModifyParm = 373.333;
    example.DigitDeltTime = 760;
    example.AziSytemError = 177.177;
    example.EleSytemError = 0.004;


    //保存
    FILE *out;

    out = fopen("saveHJParam.txt", "w");
    if(out)
    {
        	//保存ACU参数
        fprintf(out,"[ACU parament]\n");
        fprintf(out,"%hhd %lf %lf %lf %lf",
        example.IMUAB,
        example.acu_control_parm,
        example.acu_control_parm_up_k,
        example.acu_control_parm_up,
        example.acu_control_parm_V
        );
        //fputs("\n", out);
        fprintf(out,"\n");

        fprintf(out,"[filter parament]\n");
        //保存滤波参数
        fprintf(out,"%lf %lf %lf",
        example.A_filter,
        example.B_filter,
        example.nTrackNum
        );
        fputs("\n", out);
        fprintf(out,"[bomen  parament]\n");
        //保存 波门参数
        fprintf(out,"%lf %lf %lf %lf %u %u %u",
        example.faiBomen,
        example.eleBomen,
        example.fm_faiBomen,
        example.fm_eleBomen,
        example.MemoryAsureTime,
        example.FMToDbfTime,
        example.MemoryTime
        );
        fputs("\n", out);

        //保存 目标确认参数
        fprintf(out,"[target sure parament]\n");
        fprintf(out,"%u %u %lf %lf %lf %lf %lf %u %lf %lf",
        example.N_Parm,
        example.M_Parm,
        example.UBomen,
        example.VBomen,
        example.AmpAsure,
        example.AmpUpDown,
        example.ACUModifyParm,
        example.DigitDeltTime,
        example.AziSytemError,
        example.EleSytemError
        );
        fputs("\n", out);
    }

    //fprintf(out, "end of file....");
    fclose(out);
    printf("Save over.....\n");
    showstruct(&example);


    //读取
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
    printf("Filename = %s\n", Filename);
    //vDispDebugMessage(Filename);
    Fp = fopen(Filename,"rb");

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

            //抽取键名
            vExtractKeyline(line1,Keyname);
            //抽取键值行
            vExtractKeyline(line2,Keyline);

            printf(" Keyname = %s \n",Keyname);
            printf(" Keyline = %s \n",Keyline);


            if( (!(IsDone & 0x01)) &&  strcmp(Keyname,"[ACU parament]") == 0 )
            {
                NofV=5;
                //printf("dddddddddddddddd......\n");
                if(bExtractKeyvalue(Keyline,Keyname,NofV,Keyvalue))
                {
                    printf("%s \n",Keyvalue[0]);

                    ReadHJ.IMUAB                 = (unsigned char)atoi(Keyvalue[0]);
                    ReadHJ.acu_control_parm      = atof(Keyvalue[1]);
                    ReadHJ.acu_control_parm_up_k = atof(Keyvalue[2]);
                    ReadHJ.acu_control_parm_up   = atof(Keyvalue[3]);
                    ReadHJ.acu_control_parm_V    = atof(Keyvalue[4]);
                }
                IsDone = IsDone | 0x01;
            }

            if((!(IsDone & 0x02)) &&  strcmp(Keyname,"[filter parament]")== 0)
            {
                NofV=3;
                if(bExtractKeyvalue(Keyline,Keyname,NofV,Keyvalue))
                {
                    ReadHJ.A_filter      = atof(Keyvalue[0]);
                    ReadHJ.B_filter      = atof(Keyvalue[1]);
                    ReadHJ.nTrackNum     = atof(Keyvalue[2]);
                }
                IsDone = IsDone | 0x02;
            }

            if((!(IsDone & 0x10)) &&  strcmp(Keyname,"[bomen  parament]")==0)
            {
                NofV=7;
                if(bExtractKeyvalue(Keyline,Keyname,NofV,Keyvalue))
                {
                    ReadHJ.faiBomen                 = atof(Keyvalue[0]);
                    ReadHJ.eleBomen                 = atof(Keyvalue[1]);

                    ReadHJ.fm_faiBomen              = atof(Keyvalue[2]);
                    ReadHJ.fm_eleBomen              = atof(Keyvalue[3]);

                    ReadHJ.MemoryAsureTime          = (unsigned int)atoi(Keyvalue[4]);
                    ReadHJ.FMToDbfTime              = (unsigned int)atoi(Keyvalue[5]);
                    ReadHJ.MemoryTime               = (unsigned int)atoi(Keyvalue[6]);

                }
                IsDone = IsDone | 0x10;
            }

            if((!(IsDone & 0x20)) &&  strcmp(Keyname,"[target sure parament]")==0)
            {
                NofV=10;
                if(bExtractKeyvalue(Keyline,Keyname,NofV,Keyvalue))
                {
                    ReadHJ.N_Parm                 = (unsigned int)atoi(Keyvalue[0]);
                    ReadHJ.M_Parm                 = (unsigned int)atoi(Keyvalue[1]);
                    ReadHJ.UBomen                 = atof(Keyvalue[2]);
                    ReadHJ.VBomen                 = atof(Keyvalue[3]);
                    ReadHJ.AmpAsure               = atof(Keyvalue[4]);
                    ReadHJ.AmpUpDown              = atof(Keyvalue[5]);

                    ReadHJ.ACUModifyParm          = atof(Keyvalue[6]);
                    ReadHJ.DigitDeltTime          = (unsigned int)atoi(Keyvalue[7]);
                    ReadHJ.AziSytemError          = atof(Keyvalue[8]);
                    ReadHJ.EleSytemError          = atof(Keyvalue[9]);
                }
                IsDone = IsDone | 0x20;
                //Result=0;
            }

        }

        /*关闭文件*/
        fclose(Fp);
    }
    else
    {

    }
    printf("\n\n\nRead over.....\n");
    showstruct(&ReadHJ);

    printf("function: [%s], filename: %s,File Path:%s, %d, Time: %s\n",__func__,Filename,__FILE__,__LINE__);


    return 0;
}
