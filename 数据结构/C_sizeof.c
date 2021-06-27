#include<stdio.h>
#include<signal.h>
#include<time.h>
#include<string.h>
#include <unistd.h>


typedef unsigned long ULONG;
typedef enum {FALSE = 0, TRUE = 1}BOOL;
typedef unsigned char UCHAR;
// HJ GET rapidio data
typedef struct TAP_HJ_ABTION_BAND_DATA_MSG
{
	unsigned short TimeStampL; //时间低
	unsigned char LockFlag;  // 锁定指示
	unsigned char FrameStart;  // 帧头
	unsigned short TimeStampH; //时间高
	unsigned short TimeStampM; //时间中

#if 0
	unsigned short  UAZ1:1;   //方位误差电压符号位
	unsigned short  UAZ:15;   //方位误差电压，
	unsigned short  Uel1:1;    //俯仰误差电压符号位
	unsigned short  Uel:15;    //俯仰误差电压
#endif
	short  Uel;    //俯仰误差电压
	short  UAZ;   //方位误差电压，

	unsigned char AGCH;  //db整数
	unsigned short AGCL;   //db小数
	char SNR;            //估计的和信号信噪比 ，量化单位为0.5db
} TAP_HJ_ABTION_BAND_DATA_MSG;

// 检测输出的结构体
typedef struct TAP_HJ_GET_FM_FPGA_DATA_MSG
{
	unsigned long long len;

	unsigned int   FrameStart1;  // 帧头
	unsigned short FrameStart2;  // 帧头
	unsigned short FrameStart3;  // 帧头

	unsigned int	Second		:6;		//秒
	unsigned int	Minute		:6;		//分钟
	unsigned int	Hour		:6;		//小时
	unsigned int	Day			:10;	//天
	unsigned int	Bak			:4;		//保留位
	unsigned int 	uSecond;			//微秒

	unsigned long long reserve1;

	unsigned long long LRFlag;

	unsigned short BeamNo14;  // 波束4编号
	unsigned short BeamNo13;  // 波束3编号
	unsigned short BeamNo12;  // 波束2编号
	unsigned short BeamNo11;  // 波束1编号
	// unsigned long long BeamNo1;
	// unsigned long long BeamNo2;
	unsigned short BeamNo24;  //  波束8编号
	unsigned short BeamNo23;  //  波束7编号
	unsigned short BeamNo22;  //  波束6编号
	unsigned short BeamNo21;  //  波束5编号
	unsigned long long AMP1;
	unsigned long long AMP2;
	unsigned long long AMP3;
	unsigned long long AMP4;
	unsigned long long AMP5;
	unsigned long long AMP6;
	unsigned long long AMP7;
	unsigned long long AMP8;
	unsigned long long FFT1;
	unsigned long long FFT2;
	unsigned long long FFT3;
	unsigned long long FFT4;
	unsigned long long FFT5;
	unsigned long long FFT6;
	unsigned long long FFT7;
	unsigned long long FFT8;
	unsigned long long reserve2;
	unsigned long long reserve3;
} TAP_HJ_GET_FM_FPGA_DATA_MSG;

typedef struct TAP_HJ_GET_SM_FPGA_DATA_MSG
{
	unsigned long long len;

	unsigned int FrameStart1;  // 帧头
	unsigned short FrameStart2;  // 帧头
	unsigned short FrameStart3;  // 帧头

	unsigned int	Second		:6;		//秒
	unsigned int	Minute		:6;		//分钟
	unsigned int	Hour		:6;		//小时
	unsigned int	Day			:10;	//天
	unsigned int	Bak			:4;		//保留位
	unsigned int 	uSecond;			//微秒

	unsigned long long reserve1;
	unsigned long long LRFlag;

	unsigned short BeamNo11;  // 波束1编号
	unsigned short BeamNo12;  // 波束2编号
	unsigned short BeamNo13;  // 波束3编号
	unsigned short BeamNo14;  // 波束4编号
	// unsigned long long BeamNo1;
	// unsigned long long BeamNo2;
	unsigned short BeamNo21;  //  波束5编号
	unsigned short BeamNo22;  //  波束6编号
	unsigned short BeamNo23;  //  波束7编号
	unsigned short BeamNo24;  //  波束8编号

	unsigned long long AMP1;
	unsigned long long AMP2;
	unsigned long long AMP3;
	unsigned long long AMP4;
	unsigned long long AMP5;
	unsigned long long AMP6;
	unsigned long long AMP7;
	unsigned long long AMP8;
	unsigned long long FFT1;
	unsigned long long FFT2;
	unsigned long long FFT3;
	unsigned long long FFT4;
	unsigned long long FFT5;
	unsigned long long FFT6;
	unsigned long long FFT7;
	unsigned long long FFT8;

	unsigned short JCIndex1;  // 检测频率索引1
	unsigned short JCIndex2;  // 检测频率索引2
	unsigned short JCIndex3;  // 检测频率索引3
	unsigned short JCIndex4;  // 检测频率索引4

	unsigned short JCIndex5;  //  检测频率索引5
	unsigned short JCIndex6;  //  检测频率索引6
	unsigned short JCIndex7;  //  检测频率索引7
	unsigned short JCIndex8;  //  检测频率索引8
} TAP_HJ_GET_SM_FPGA_DATA_MSG;

// HJ GET_SUMDIFF_FPGA rapidio data
typedef struct TAP_HJ_GET_SUMDIFF_FPGA_DATA_MSG
{
	unsigned long long len;
	unsigned int FrameStart1;  // 帧头
	unsigned short FrameStart2;  // 帧头
	unsigned short FrameStart3;  // 帧头

	//	unsigned long long GPSTime;

	unsigned int	Second		:6;		//秒
	unsigned int	Minute		:6;		//分钟
	unsigned int	Hour		:6;		//小时
	unsigned int	Day			:10;	//天
	unsigned int	Bak			:4;		//保留位
	unsigned int 	uSecond;			//微秒

	unsigned long long reserve1;

	long long leftSum;
	long long reserve2;
	long long leftAzI;
	long long leftAzQ;
	long long leftEleI;
	long long leftEleQ;

	long long rightSum;
	long long reserve3;
	long long rightAzI;
	long long rightAzQ;
	long long rightEleI;
	long long rightEleQ;

	long long reserve4[6];
} TAP_HJ_GET_SUMDIFF_FPGA_DATA_MSG;

typedef struct TAP_HJ_GET_SUMAMP_FPGA_DATA_MSG
{
	unsigned long long len;

	unsigned int FrameStart1;  // 帧头
	unsigned short FrameStart2;  // 帧头
	unsigned short FrameStart3;  // 帧头

	// unsigned long long GPSTime;
	unsigned int	Second		:6;		//秒
	unsigned int	Minute		:6;		//分钟
	unsigned int	Hour		:6;		//小时
	unsigned int	Day			:10;	//天
	unsigned int	Bak			:4;		//保留位
	unsigned int 	uSecond;			//微秒

	unsigned long long reserve1;
	unsigned long long leftX1;
	unsigned long long leftX2;
	unsigned long long leftX3;
	unsigned long long leftX4;
	unsigned long long leftX5;
	unsigned long long leftX6;
	unsigned long long leftX7;
	unsigned long long leftX8;
	unsigned long long leftX9;
	unsigned long long rightX1;
	unsigned long long rightX2;
	unsigned long long rightX3;
	unsigned long long rightX4;
	unsigned long long rightX5;
	unsigned long long rightX6;
	unsigned long long rightX7;
	unsigned long long rightX8;
	unsigned long long rightX9;
} TAP_HJ_GET_SUMAMP_FPGA_DATA_MSG;

// HJ GET band data
typedef struct TAP_ABTION_RAPIDIO_DATA_MSG
{
	unsigned char			       		ucDDCid;			//用来区分以下的结构体
	TAP_HJ_ABTION_BAND_DATA_MSG    		pBandReMsg;     // ucDDCid = 0调频,1扩频,2扩测
	TAP_HJ_GET_FM_FPGA_DATA_MSG    		pDBFFMMsg;
	TAP_HJ_GET_SM_FPGA_DATA_MSG    		pDBFSMMsg;
	TAP_HJ_GET_SUMDIFF_FPGA_DATA_MSG 	pDBFSDMsg;
	TAP_HJ_GET_SUMAMP_FPGA_DATA_MSG 	pDBFSAMsg;
} TAP_ABTION_RAPIDIO_DATA_MSG;


/* 测角数据结构IQ */
typedef struct DirectionPLOTIQ
{
    struct                      DirectionPLOTIQ* Prev;     /* 双链结构：前一指针 */
    struct                      DirectionPLOTIQ* Next;      /* 双链结构：后一指针 */
    unsigned char           ucDDCid;      // 用于区分是哪个，1：调频； 2：扩频；3：扩测，6：7波束调频；7:7波束单频；8:和差波束；9:9波束
	TAP_HJ_ABTION_BAND_DATA_MSG       pBandReMsg;
 	TAP_HJ_GET_FM_FPGA_DATA_MSG       pDBFFMMsg;
 	TAP_HJ_GET_SM_FPGA_DATA_MSG       pDBFSMMsg;
 	TAP_HJ_GET_SUMDIFF_FPGA_DATA_MSG  pDBFSDMsg;
 	TAP_HJ_GET_SUMAMP_FPGA_DATA_MSG   pDBFSAMsg;
}DirectionPLOTIQ;

/* 系统工作参数 */
typedef struct TAP_HJSYS_PARM_MANAGE
{
	unsigned int		TaskMask;
	char				mid[10];
	unsigned char		FlatState;    //系统运行方式，1车载静止、2车载机动、3船载机动
	unsigned char		capture;      //捕获方式	1：自动任务   2：手动任务
	unsigned char		RRFFreq1Flag; //自动捕获有效 0:无此参数1:自动2：数引捕获3：程引捕获
	unsigned char		RRFFreq2Flag;
	unsigned char		CurWorkType;  		// 波控工作方式控制-工作方式
	unsigned char		CurWorkTypeLast;  	//
	unsigned char		TaskStaus;  		// 波控工作方式控制
	unsigned char		sendDataType;	//0:无此参数 1:常送2:人工3:选送
	unsigned char		SendDataState;
	unsigned char		AngleSaveState;    //存盘控制

	unsigned char		OrbitPredictStatus;    //yuba0
	unsigned char		DigitalLeadStatus;
	unsigned char		MultiBeamStatus;
	unsigned char		FMAngleErrStatus;
	unsigned char		SSMeaErrStatus;
	unsigned char		SSTeleErrStatus;

    unsigned char		IMU1Flag;
    unsigned char		IMU2Flag;

	ULONG		MultiBeamTime;
	ULONG		FMAngleErrTime;
	ULONG		SSMeaErrTime;
	ULONG		SSTeleErrTime;

	unsigned long		AngleEffective;


	int                     DigleadAzi;
	int                     DigleadElev;
	int                     MultiBeamAzi;
	int                     MultiBeamElev;
	int                     TraLeadAzi;
	int                     TraLeadElev;

	double                     fFMAziErrVol;
	double                     fFMElevErrVol;
	double                     fSSMeaAziErrVol;
	double                     fSSMeaElevErrVol;
	double                     fSSTeleAziErrVol;
	double                     fSSTeleElevErrVol;

	double		fFMAGCVol;
	double		fSSMeaAGCVol;
	double		fSSTeleAGCVol;
	double		fFMSNRVol;
	double		fSSMeaSNRVol;
	double		fSSTeleSNRVol;

	//应急写入起飞时
	unsigned int            T0Day;
	unsigned int            T0Time;
	double					T0mjday;
	BOOL					bT0flag;//应急写入起飞时

	unsigned char		CPUUse;
	unsigned char		RAMUse;
	unsigned long		upFreq;
	unsigned long		downFreq;
	unsigned char		bf1;
	unsigned char		bf2;
	unsigned long		f1;
	unsigned long		f2;
	unsigned char		captureTimeTH;// time 1--10s
	unsigned char		AngleProcFlag;
	unsigned short		reportCyc;

	char				FilterInitT;
	char				FilterInitNum;
	unsigned int		Reserve[4]; //

	//站址坐标装订
	double				longitude;
	double				lat;
	double				high;
	double 			    yaw; //hangxiang
	double   			roll; //fangun
	double   			pitch; //fuyang  //站址坐标装订
	unsigned char		ZenithPassStatus;

	double				VE;
	double				VN;
	double				VH;
	double				Xpos;  // 上帧的位置
	double				Ypos;
	double				Zpos;
	unsigned char		AimFlag; 	//  波控工作方式控制- 等待点位置目标标识，1:位置 2： 角度   3： 相对时
	double				Xwait;      // 波控工作方式控制- 地心系等待点位置，捕获时控伺服
	double				Ywait;		// 波控工作方式控制- 地心系等待点位置，捕获时控伺服
	double				Zwait;		// 波控工作方式控制- 地心系等待点位置，捕获时控伺服
	float					startElev;
	float					stopElev;
	unsigned int       Date;
	float       Time;

	//跟踪失效设置
	unsigned char				Select1;
	unsigned char				Select2;
	unsigned char               Select3;
	unsigned char               MemoryTrackTime;//跟踪失效设置

	unsigned short      A1;
	unsigned short      E1;
	unsigned short      A2;
	unsigned short      E2;
	unsigned short      SBF;

	//add process
    unsigned char		CurWorkTypeR;// 当前工作方式 // 2:bao 3:bubao
    unsigned char		TaskStausBH;
    ULONG				digitDataTime; // 数据时标
    // pro
    unsigned char 		ucDDCid;  			// 类似航迹号，有效值1-8

    //角度零值装订
    float    	AziZero;
    float   	ElevZero;//角度零值装订

    //角度偏置设置
    unsigned char		AngleOffsetFlag;
    float   			ferrAzi;
    float   			ferrEle;
    int   				errTime;

    //测角修正值装订
    float				 	MaxOutLevelAngle;
    float   				MaxOutLevelAzi;
    float   				Sb;
    float					Cs;
    float   				Ce;
    float   				Eg;//测角修正值装订

    unsigned short    		C_A;
    unsigned short    		C_E;
    // status
	int                 CurAzi;
	int                 CurElev;
	int                 CmdAzi;
	int                 CmdElev;
	int                 StationAzi;
	int                 StationElev;

	//数引数据
	double					X;  // 数引X
	double					Y;  // 数引Y
	double					Z;  // 数引Z
	double					VX; // 速度VX
	double					VY; // 速度VY
	double					VZ; // 速度VZ
	double 					mjday;//数引数据

    double	BANDR;  	// 基带测距R,band R
    ULONG	BANDRTime;  // 基带测距的时间
    BOOL	bBandFlag; 	// 基带测距有效标识

    double	SR;  	    // 数引R
    ULONG	SRTime;  	// 数引R的时间
    BOOL	SRFlag; 	// 数引R有效标识

    double	CR;  	    // 程引R
    ULONG	CRTime;  	// 程引R的时间
    BOOL	CRFlag; 	// 程引R有效标识

	BOOL	bTrackReport; //航迹上报标志

	long   f0;				// 中心频率
	double beam_fai;		// 方位角, 中心波束指向, 初始值由程引开始位置决定
	double beam_seta;		// 俯仰角, 中心波束指向, 初始值由程引开始位置决定

    // ACU
	int					nAcuFirst;
    double				ACU_Azloc;
    double				ACU_Eleloc;
    double				ACU_AzEcef;   // *波控工作方式控制- 角度--大地系方位角，捕获时控伺服
    double				ACU_EleEcef;  // *波控工作方式控制- 角度--大地系俯仰角，捕获时控伺服
    unsigned char		bACU_First;
    double				ACU_AzEceft;
    double				ACU_EleEceft;

    double				ACU_REcef;
    double				LLTV_AzEcef;
    double				LLTV_EleEcef;

    // LLTV
    short			MissAzi;   // 方位脱靶亮
    short			MissElev;	// 俯仰脱靶量
    int				StarPosAzi; // 星位置方位
    int				StarPosElev; //  星位置俯仰

    //
	int                 FMAzi;
	int                 FMElev;
	int                 SSMeaAzi;
	int                 SSMeaElev;
	int                 SSTeleAzi;
	int                 SSTeleElev;

	int                 CheckAzi;
	int                 CheckElev;
	int                 SumDiffAzi;
	int                 SumDiffElev;

	// add angle
	ULONG				AngleEffectiveTime; // 数据时标
	int                 ProgramAziM;    //程引
	int                 ProgramElevM;	//程引
	int                 ProgramAzi;		//程引
	int                 ProgramElev;	//程引

	int                 DigleadAziM;
	int                 DigleadElevM;

	unsigned char		TZLeadStatus;
	int                 TZleadAzi;    //大地系方位角，测角结果(阵面)转成大地的结果
	int                 TZleadElev;   //大地系方位角，测角结果(阵面)转成大地的结果
	int                 TZleadAziM;
	int                 TZleadElevM;

	int                 RealTGroundAzi;
	int                 RealTGroundElev;
	int                 RealTMeasureAzi;
	int                 RealTMeasureElev;

	double              dElecBeamAzi;   //电波束指向
	double              dElecBeamElev;	//电波束指向
    unsigned char		TrackScanFirst;
    unsigned char		scanfFirst;
    unsigned char		SureFirst;

    //波束扫描控制
    unsigned int		BeamNum;    		//波个个数
    unsigned int		ScanNum;   			// 扫描次数
    unsigned int		ScanMood;  			//1捕获，2跟踪
    unsigned char		ScanMoodReport;     //
    unsigned int		ScanInterbal;       //捕获脉冲间隔
    unsigned int		captureInter;       //跟踪脉冲间隔
    double				bpAz[65];           //37或65个模拟波位在阵面系下的方位，相对于捕获时下发的等待点的方位
    double				bpEle[65];          //37或65个模拟波位在阵面系下的俯仰，相对于捕获时下发的等待点的俯仰

    unsigned char       TargetSure;//相关
    unsigned char       TrackingMode; // 当前跟踪方式1：待机     2：手摇    3：指向    4：数引    5：程引     6：记忆跟踪
    double				ScanAz;
    double				ScanEle;
    unsigned char       TargetSureMode;
    double				gScanAz;
    double				gScanEle;
	unsigned long		lStartTime;
	unsigned long		lEndTimeTime;
	// add
	unsigned char		DTEStatus;
    unsigned char		ACUStatus;
	unsigned char		LLTVStatus;
    unsigned char		ASCStatus;
    unsigned char		MIUStatus;

    unsigned char		MNBW;
    unsigned char		DeltTime;

    unsigned char		BCNlog;			// 工作日志上报
    unsigned char		workmood; 		// 工作模式  1：任务模式  2：联调模式
	long				gLastProcessTime;
	long				gPreProcessTime;

	long 				gWorkT0Time;
	short				gWorkDeltTime; //   波控工作方式控制-  工作方式下发的相对时

}TAP_HJSYS_PARM_MANAGE;

//海基目标起始结构体
/*点迹信息*/
typedef struct PLOT_BASE_INFO_CO
{
    ULONG        dSystemTime;                           /*! 时间 */
    double      dRange;                                /*! 距离 */
    double	     dAzimuth;                              /*! 方位 */
    double	     dElevation;                            /*! 俯仰 */
	double	     xlocal;                                /*! x方向余弦 */
	double	     zlocal;                           	   /*! z方向余弦 */
    double		 dAmp; 								   // 目标幅度
    double      dsore;								   // 目标质量
    UCHAR		 circle;								   // 圈数
    UCHAR		 bp; 								   // 模拟波位号
    UCHAR		 sbp; 								   // 数字波位号
}PLOT_BASE_INFO_CO;

/*!  相关点迹信息 */
typedef struct PLOT_MANAGE_CO
{
	BOOL        bUsedFlag;                              /*!< 是否已经在使用标志*/
    ULONG       dSystemTime;                           /*! 时间 */
    unsigned short    Frame;                            /*!  更新帧数 */
    PLOT_BASE_INFO_CO plot[5];
}PLOT_MANAGE_CO;

typedef struct STRUCT1
{
    int a ;
    double b;
    float c;
    unsigned char d;
    int e;
    int f;
} STR1;


typedef struct STRUCT2
{
    int a ;
    double b;
    float c;
    unsigned char d;
    //int e;
    //int f;
} STR2;

enum
{
	ENUM_SCAN_RESET= 0,				// 复位
	ENUM_SCAN_SCAN = 1,				// 扫描
	ENUM_SCAN_POINT = 2,			// 指向--跟踪
	ENUM_SCAN_TRACK = 3,    		// 跟踪
	ENUM_SCAN_ZERO_POINT = 4,		// 中心波束
	ENUM_SCAN_OPEN_POINT= 5,		// 开环跟踪
	ENUM_SCAN_RECORD_POINT = 6,		// 闭环跟踪
	ENUM_SCAN_MEAR_POINT = 7,     	// 测量
	ENUM_SCAN_XYZFILTER_POINT = 8,  // x,y,z跟踪
	ENUM_SCAN_SMOOTH_POINT = 9,     // 平滑
	ENUM_SCAN_OPEN_POINT_MOVE = 10  // 开环波束调度测试
};

void showstr(STR2 *p)
{
    printf("a = %d, b = %lf, c = %f, d = %hhu, \n",p->a,p->b,p->c,p->d);
}

int main()
{
    long double          A1[4] = {12.12, 13.13, 14.14, 15.15};
    long double  *LongDoubleP = NULL;


	double               A[4] = {12.12, 13.13, 14.14, 15.15};
	double  *DoubleP = NULL;

	int                  B[4] = {12 , 13 , 14 , 15 };
	int  *IntP = NULL;

	float                C[4] = {12.21 , 13.31 , 14.41 , 15.51 };
	float  *FloatP = NULL;

	char                     D[4] = {'a' , 'b' , 'c' , 'd' };
	char  *CharP = NULL;

	unsigned int             E[4] = {12 , 13 , 14 , 15 };
	unsigned int  *UintP = NULL;

    short int                F[4] = {12 , 13 , 14 , 15 };
    short int  *SintP = NULL;

    unsigned short int       G[4] = {12 , 13 , 14 , 15 };
    unsigned short int   *USintP = NULL;

    long int                 H[4] = {12 , 13 , 14 , 15 };
    long int  *LintP = NULL;

    unsigned long int        I[4] = {12 , 13 , 14 , 15 };
    unsigned long int    *ULintP = NULL;

    long long int            J[4] = {12 , 13 , 14 , 15 };
    long long int  *LLintP = NULL;

    unsigned long long int K[4] = {12 , 13 , 14 , 15 };
    unsigned long long int  *ULLintP = NULL;

	printf("sizeof(A1) = %d\n", sizeof(A1));
	printf("sizeof(long double) = %d\n", sizeof(long double));
	printf("sizeof(long double  *) = %d\n", sizeof(long double  *));

	printf("sizeof(A) = %d\n", sizeof(A));
	printf("sizeof(double) = %d\n", sizeof(double));
	printf("sizeof(double *) = %d\n", sizeof(double *));


	printf("sizeof(B) = %d\n", sizeof(B));
	printf("sizeof(int) = %d\n", sizeof(int));
	printf("sizeof(int *) = %d\n", sizeof(int *));


	printf("sizeof(C) = %d\n", sizeof(C));
	printf("sizeof(float) = %d\n", sizeof(float));
	printf("sizeof(float *) = %d\n", sizeof(float *));


	printf("sizeof(D) = %d\n", sizeof(D));
	printf("sizeof(char) = %d\n", sizeof(char));
	printf("sizeof(char *) = %d\n", sizeof(char *));


	printf("sizeof(E) = %d\n", sizeof(E));
	printf("sizeof(unsigned int) = %d\n", sizeof(unsigned int));
	printf("sizeof(unsigned int *) = %d\n", sizeof(unsigned int *));


	printf("sizeof(F) = %d\n", sizeof(F));
	printf("sizeof(short int) = %d\n", sizeof(short int));
	printf("sizeof(short int *) = %d\n", sizeof(short int *));

 	printf("sizeof(G) = %d\n", sizeof(G));
	printf("sizeof(unsigned short int) = %d\n", sizeof(unsigned short int));
	printf("sizeof(unsigned short int *) = %d\n", sizeof(unsigned short int *));

	printf("sizeof(H) = %d\n", sizeof(H));
    printf("sizeof(long int) = %d\n", sizeof(long int));
    printf("sizeof(long int *) = %d\n", sizeof(long int *));

	printf("sizeof(I) = %d\n", sizeof(H));
	printf("sizeof(unsigned long int) = %d\n", sizeof(unsigned long int));
	printf("sizeof(unsigned long int *) = %d\n", sizeof(unsigned long int *));


	printf("sizeof(J) = %d\n", sizeof(I));
	printf("sizeof(long long int) = %d\n", sizeof(long long int));
	printf("sizeof(long long int *) = %d\n", sizeof(long long int *));


	printf("sizeof(K) = %d\n", sizeof(J));
	printf("sizeof(unsigned long long int) = %d\n", sizeof(unsigned long long int));
	printf("sizeof(unsigned long long int *) = %d\n", sizeof(unsigned long long int *));



    printf("sizeof(TAP_HJSYS_PARM_MANAGE) = %d\n", sizeof(TAP_HJSYS_PARM_MANAGE));  //系统工作参数

	printf("sizeof(TAP_HJ_ABTION_BAND_DATA_MSG) = %d\n", sizeof(TAP_HJ_ABTION_BAND_DATA_MSG));// 基带发给BCN结构体
	printf("sizeof(TAP_HJ_GET_FM_FPGA_DATA_MSG) = %d\n", sizeof(TAP_HJ_GET_FM_FPGA_DATA_MSG));// DBF发给BCN的调频结构体
	printf("sizeof(TAP_HJ_GET_SM_FPGA_DATA_MSG) = %d\n", sizeof(TAP_HJ_GET_SM_FPGA_DATA_MSG));// DBF发给BCN的单频结构体
	printf("sizeof(TAP_HJ_GET_SUMDIFF_FPGA_DATA_MSG) = %d\n", sizeof(TAP_HJ_GET_SUMDIFF_FPGA_DATA_MSG));// DBF发给BCN的和差结构体
    printf("sizeof(TAP_HJ_GET_SUMAMP_FPGA_DATA_MSG) = %d\n", sizeof(TAP_HJ_GET_SUMAMP_FPGA_DATA_MSG));// DBF发给BCN的9波束结构体
	printf("sizeof(TAP_ABTION_RAPIDIO_DATA_MSG) = %d\n", sizeof(TAP_ABTION_RAPIDIO_DATA_MSG));   //
	printf("sizeof(DirectionPLOTIQ) = %d\n", sizeof(DirectionPLOTIQ));


	STR1 S1;
	S1.a = 12;
	S1.b = 12.12;
	S1.c = 13.13;
	S1.d = 14;
	S1.e = 101;
	S1.f = 111;

	STR2 *p2 = &S1;

	showstr(p2);

    int a = ENUM_SCAN_SCAN;

    if(a == 1)
    {
        printf("aaaa\n");
    }
    return 0;

}





