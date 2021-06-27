#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#define MaxLen  512

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


    //showstruct(&Save);

    //读取
        //ReadHJ = (TAP_HJ_CONTRL_REAL_DATA_MSG  *)malloc(sizeof(TAP_HJ_CONTRL_REAL_DATA_MSG));
/*
    ReadHJ.IMUAB = 0;
    ReadHJ.acu_control_parm = 0;
    ReadHJ.acu_control_parm_up_k = 0;
    ReadHJ.acu_control_parm_up = 0;
    ReadHJ.acu_control_parm_V = 0;
    ReadHJ.A_filter = 0;
    ReadHJ.B_filter = 0;
    ReadHJ.nTrackNum = 0;
	ReadHJ.faiBomen = 0;
	ReadHJ.eleBomen = 0;
	ReadHJ.fm_faiBomen = 0;
	ReadHJ.fm_eleBomen = 0;
	ReadHJ.MemoryAsureTime = 0;
	ReadHJ.FMToDbfTime = 0;
	ReadHJ.MemoryTime = 0;
	ReadHJ.N_Parm = 0;
	ReadHJ.M_Parm = 0;
	ReadHJ.UBomen = 0;
	ReadHJ.VBomen = 0;
	ReadHJ.AmpAsure = 0;
	ReadHJ.AmpUpDown = 0;
	ReadHJ.ACUModifyParm = 0;
	ReadHJ.DigitDeltTime = 0;
	ReadHJ.AziSytemError = 0;
	ReadHJ.EleSytemError = 0;
*/

    TAP_HJ_CONTRL_REAL_DATA_MSG  *ReadHJ;
    ReadHJ = (TAP_HJ_CONTRL_REAL_DATA_MSG  *)malloc(sizeof(TAP_HJ_CONTRL_REAL_DATA_MSG));


    char Filename[200];
    char mes[MaxLen];
    strcat(Filename, "/cfg/tapconfig.cfg");//换文件名

    FILE *Rin;
    Rin = fopen("saveHJParam.txt", "r");
    if(Rin)
    {
     	//读取ACU参数
     	fgets(mes, MaxLen, Rin);
     	fputs(mes, stdout);

        fscanf(Rin,"%hhd %lf %lf %lf %lf\n",&(ReadHJ->IMUAB), &(ReadHJ->acu_control_parm), &(ReadHJ->acu_control_parm_up_k), &(ReadHJ->acu_control_parm_up),&(ReadHJ->acu_control_parm_V));
        //getc(Rin);

        //读取滤波参数
        //getchar();
     	fgets(mes, MaxLen, Rin);
     	fputs(mes, stdout);
        fscanf(Rin,"%lf %lf %lf\n",&(ReadHJ->A_filter),&(ReadHJ->B_filter),&(ReadHJ->nTrackNum));
        //getc(Rin);

        //波门参数
     	fgets(mes, MaxLen, Rin);
     	fputs(mes, stdout);
        fscanf(Rin,"%lf %lf %lf %lf %u %u %u\n",&(ReadHJ->faiBomen),&(ReadHJ->eleBomen),&(ReadHJ->fm_faiBomen),&(ReadHJ->fm_eleBomen),&(ReadHJ->MemoryAsureTime),&(ReadHJ->FMToDbfTime),&(ReadHJ->MemoryTime));
        //getc(Rin);

        //目标确认参数
     	fgets(mes, MaxLen, Rin);
     	fputs(mes, stdout);
        fscanf(Rin,"%u %u %lf %lf %lf %lf %lf %u %lf %lf\n",&(ReadHJ->N_Parm),&(ReadHJ->M_Parm),&(ReadHJ->UBomen),&(ReadHJ->VBomen),&(ReadHJ->AmpAsure),&(ReadHJ->AmpUpDown),&(ReadHJ->ACUModifyParm),&(ReadHJ->DigitDeltTime),&(ReadHJ->AziSytemError),&(ReadHJ->EleSytemError));
        //getc(Rin);
    }

    //fscanf(Rin, "d ", &(ReadHJ.IMUAB));
    //fscanf(Rin, "f ", &(ReadHJ.acu_control_parm));
    fclose(Rin);
    printf("\n\n\nRead over.....\n");
    showstruct(ReadHJ);

    printf("[%s] Config File Path:%s -- %s:%d\n",__func__,Filename,__FILE__,__LINE__);


    return 0;
}
