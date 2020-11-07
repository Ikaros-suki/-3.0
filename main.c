/*************************************
**程序描述:用于管理学生成绩
**日期:2020/11/07
**作业题目:StudentScoreManager
**输入:choice
**输入范围:0-11
**输出:视输入情况而定
**作者:坂井 离人
**版本:3.0.0
**************************************
*/



#include<stdio.h>
#include<string.h>

void Input(int *i_StudentNum, int *i_course, long StudentID[], float score[][6], char name[][20]);
//输入数据的函数
void Calculate(int i_course, int i_StudentNum, long StudentID[], float score[][6]);
//计算并输出学生总分,平均分的函数
void CalculateS(int i_course, float score[][6], int i);
//计算每门课程的总分和平均分
void CalculateP(int i_course, float score[][6], int i_StudentNum, float f_sum[]);
//单纯计算每个学生的总分和平均分
int Compare(float a, float b);
//比较大小的函数
void DescendingScore(int i_StudentNum, float f_sum[], long StudentID[], float Rank[], int (*Compare)(float a, float b), char name[][20]);
//按每个学生的总分由高到低排出名次表的函数
void AscendingScore(int i_StudentNum, float f_sum[], long StudentID[], float Rank[], int (*Compare)(float a, float b), char name[][20]);
//按每个学生的总分由低到高排出名次表的函数
void AscendingID(int i_StudentNum, float f_sum[], long StudentID[], float Rank[], char name[][20]);
//按学号由小到大排出成绩表的函数
void Search(int i_StudentNum, long StudentID[], float score[][6], char name[][20], float f_sum[], int i_course);
//按学号查询学生排名及其各科考试成绩的函数
void Analysis(int i_StudentNum, long StudentID[], float score[][6], int i_course);
//对每门课程分别统计每个类别的人数以及所占的百分比的函数
int Check(int i, long StudentID[]);
//学号查重函数
void OutRank(float Rank[], char name[][20], float fscore[], int i_StudentNum, long StudentID);
//输出函数
void AscendingName(int i_StudentNum, float f_sum[], long StudentID[], float Rank[], char name[][20]);
//按姓名的字典顺序排出成绩表的函数
void SearchName(int i_StudentNum, long StudentID[], float score[][6], char name[][20], float f_sum[], int i_course);
//.按姓名查询学生排名及其各科考试成绩的函数

//我为每个需要输入数字的地方都加上了检验输入的是否为数字的语句

main()
{
	//一大堆变量,在函数部分会声明变量代表的意思
	int ret = 1,check = 0;
	int pi_StudentNum = 0, InputOrder[30] = {0}, i, j, median, m1, m2;
	float score[30][6] = {0}, f_sum[30] = {}, f_aver, Rank[30] = {0};
	char name[30][20] = {0};
	int choice, pi_course = 0;
	long StudentID[30] = {0};
	printf("Number:200110830\n");
	printf("subject No.7\n\n");

	printf("1.Input record\n2.List record\n3.Calculate toal and average score of course\n");
	printf("4.Sort in descending order by score\n5.Sort in ascending order by score\n");
	printf("6.Sort in ascending order by StudentID\n7.Sort in dictionary order by name\n");
	printf("8.Search by StudentID\n9.Search by name\n10.Statistic analysis\n0.Exit\nPlease enter your choice:");
	//打印选项


	do{
		scanf("%d%*c", &choice);
		//用户输入选择


		switch (choice)//根据用户的选择调用不同的函数
		{
			case 1:
				Input(&pi_StudentNum, &pi_course, StudentID, score, name);
				printf("Please enter your choice:");
				CalculateP(pi_course, score, pi_StudentNum, f_sum);
				while(getchar() != '\n');
				break;
				//在1之前加入输入学生人数
				//1:录入学生学号和考试成绩

			case 2:
				if(pi_StudentNum == 0)
					Input(&pi_StudentNum,&pi_course, StudentID, score, name);
				for (i = 0; i < pi_StudentNum; i++)
					{
						printf("%3ld   %-20s   ", StudentID[i], name[i]);
						for (j = 0; j < pi_course; j++)
						{
							printf("%.2f	", score[i][j]);
						}
						CalculateS(pi_course, score, i);
						printf("\n");
					}
				printf("Please enter your choice:");
				break;
				//输出每个学生的学号和考试成绩(按输入的顺序)(相当于复读机)

			case 3:
				if(pi_StudentNum == 0)
					Input(&pi_StudentNum,&pi_course, StudentID, score, name);
                printf("每门课程的总分和平均分如下:\n");
				Calculate(pi_course, pi_StudentNum, StudentID, score);
				printf("\n");
				printf("Please enter your choice:");
				break;
				// 计算每门课程的总分和平均分

			case 4:
				if(pi_StudentNum == 0)
					Input(&pi_StudentNum,&pi_course, StudentID, score, name);

                printf("每个学生的总分和平均分如下:\n");
				for (i = 0; i < pi_StudentNum; i++)
					{
						printf("%3ld   %-20s   ", StudentID[i], name[i]);

						CalculateS(pi_course, score, i);
						printf("\n");
					}
				printf("Please enter your choice:");
				break;
				//计算每个学生的总分和平均分

			case 5:
				if(pi_StudentNum == 0)
					Input(&pi_StudentNum,&pi_course, StudentID, score, name);
				CalculateP(pi_course, score, pi_StudentNum, f_sum);
				printf("按成绩由高到低排如下:\n");
				DescendingScore(pi_StudentNum, f_sum, StudentID, Rank, Compare, name);
				printf("\n");


				printf("Please enter your choice:");
				break;
				//按成绩由高到低排出名次表


			case 6:
				if(pi_StudentNum == 0)
					Input(&pi_StudentNum,&pi_course, StudentID, score, name);
				CalculateP(pi_course, score, pi_StudentNum, f_sum);
				printf("按成绩由低到高排如下:\n");
				AscendingScore(pi_StudentNum, f_sum, StudentID, Rank, Compare, name);
				printf("\n");
				printf("Please enter your choice:");
				break;
				//按成绩由低到高排出名次表

			case 7:
				if(pi_StudentNum == 0)
					Input(&pi_StudentNum,&pi_course, StudentID, score, name);
				CalculateP(pi_course, score, pi_StudentNum, f_sum);
				printf("按学号由小到大排如下:\n");
				AscendingID(pi_StudentNum, f_sum, StudentID, Rank, name);
				printf("\n");
				printf("Please enter your choice:");
				break;
				//按学号由小到大排出成绩表

			case 8:
				if(pi_StudentNum == 0)
					Input(&pi_StudentNum,&pi_course, StudentID, score, name);
				CalculateP(pi_course, score, pi_StudentNum, f_sum);
				printf("按姓名的字典顺序排如下:\n");
				AscendingName(pi_StudentNum, f_sum, StudentID, Rank, name);
				printf("Please enter your choice:");
				printf("\n");
				break;
				//按姓名的字典顺序排出成绩表


			case 9:
				if(pi_StudentNum == 0)
					Input(&pi_StudentNum,&pi_course, StudentID, score, name);
				CalculateP(pi_course, score, pi_StudentNum, f_sum);
				Search(pi_StudentNum, StudentID, score, name, f_sum, pi_course);
				printf("Please enter your choice:");
				printf("\n");
				while(getchar() != '\n');
				break;
				//按学号查询学生排名及成绩

			case 10:
				if(pi_StudentNum == 0)
					Input(&pi_StudentNum,&pi_course, StudentID, score, name);
				CalculateP(pi_course, score, pi_StudentNum, f_sum);
				SearchName(pi_StudentNum, StudentID, score, name, f_sum, pi_course);
				printf("Please enter your choice:");
				printf("\n");
				while(getchar() != '\n');
				break;
				//按姓名查询学生排名及其考试成绩


			case 11:
				if(pi_StudentNum == 0)
					Input(&pi_StudentNum,&pi_course, StudentID, score, name);
				Analysis(pi_StudentNum, StudentID, score, pi_course);
				printf("Please enter your choice:");
				printf("\n");
				while(getchar() != '\n');
				break;
				/*按优秀（90—100分）、良好（80—89分）、中等（70—79分）、及格（60一69分）、不及格
					(0—59分)5个类别，统计每个类别的人数以及所占的百分比*/

			case 0:
				break;
				//退出程序

			default:
				printf("\n");
				printf("Please enter your choice:");
				break;
				//若输入的不是0-11的字符,则再次输入
		}


	}while (choice != 0);


}

/**********************************
** 函数名:Input
** 输 入: *i_StudentNum, StudentID, score, name, *i_course
** *i_StudentNum---学生人数
** StudentID---学号
** score---学生成绩
** name---学生名字
** *i_course---考试科目数
** 功能描述:确定学生人数以及录入学生学号和对应的学生成绩
** 作 者:坂井 离人
** 日 期:2020.11.07
** 版本:3.0.0
************************************/
void Input(int *i_StudentNum, int *i_course, long StudentID[], float score[][6], char name[][20])
{
	int ret = 0, i = 0 ,n, check = 0, j = 0;

	for ( ; *i_StudentNum < 1 || *i_StudentNum > 30; )
	{
		//因为在主程序中,我定义*i_StudentNum为0,所以程序开始时会执行
		//若输入的学生人数不满足在1-30之间,则重新输入
		printf("请输入学生人数(1-30):");
		ret = scanf("%d", &*i_StudentNum);

		while (ret != 1)
		{
			while (getchar() != '\n');
			printf("请输入学生人数(1-30):");
			ret = scanf("%d", &*i_StudentNum);

		}
	}

	for ( ; *i_course < 1 || *i_course > 6; )
	{
		//因为在主程序中,我定义*i_StudentNum为0,所以程序开始时会执行
		//若输入的学生人数不满足在1-30之间,则重新输入
		printf("请输入科目数(1-6):");
		ret = scanf("%d", &*i_course);

		while (ret != 1)
		{
			while (getchar() != '\n');
			printf("请输入科目数(1-6):");
			ret = scanf("%d", &*i_course);

		}
	}

	for (i = 0; i < *i_StudentNum; i++)
	{

		//执行直到输入人数等于学生人数即*i_StudentNum
		printf("请输入学号:");
		ret = scanf("%d", &StudentID[i]);
			check = Check(i, StudentID);
			//Check函数用于检验学号是否重复
		while (ret != 1 || check == 1)
		{
			while (getchar() != '\n');
			printf("请输入学号:");
			ret = scanf("%ld", &StudentID[i]);
			check = Check(i, StudentID);
		}

		for (n = 0; n < i; n++)
		{
			if (StudentID[n] == StudentID[i])
			{
				while (getchar() != '\n');
				printf("请输入学号:");
				scanf("%ld", &StudentID[i]);

			}
		}

		while (getchar() != '\n');
		printf("请输入学生姓名:");
		gets(name[i]);
		//录入学生姓名并将其与学号对应

		for (j = 0; j < *i_course; j++)
		{
			printf("请输入该学生第%d门考试成绩:", j+1);
			ret = scanf("%f", &score[i][j]);
			//若成绩小于0或大于100,则重新输入
			while (ret != 1 || score[i][j] < 0 || score[i][j] >100)
			{
				while (getchar() != '\n');
				printf("请输入该学生成绩:");
				ret = scanf("%f", &score[i][j]);
			}
		}


	}
}

/**********************************
** 函数名:CalculateS
** 输 入:score, i, *i_course

** score---学生成绩
** i---某个学生
** *i_course---考试科目数
** 功能描述:计算并输出学生总分和平均分
** 作 者:坂井 离人
** 日 期:2020.11.07
** 版本:3.0.0
************************************/
void CalculateS(int i_course, float score[][6], int i)
{
	int j = 0;
	float f_aver = 0, f_sum = 0;

	for (j = 0; j < i_course; j++)
	{
		f_sum = f_sum + score[i][j];
	}
	f_aver = f_sum / i_course;
	printf("总分为%.2f,平均分为%.2f\n", f_sum, f_aver);
}


/**********************************
** 函数名:CalculateP
** 输 入: *i_StudentNum, score, *i_course, f_sum
** *i_StudentNum---学生人数

** score---学生成绩
** f_sum---学生总分
** *i_course---考试科目数
** 功能描述:单纯计算学生总分
** 作 者:坂井 离人
** 日 期:2020.11.07
** 版本:3.0.0
************************************/
void CalculateP(int i_course, float score[][6], int i_StudentNum, float f_sum[])
{
	int i = 0, j = 0;


	for (i = 0; i < i_StudentNum; i++)
	{
	    f_sum[i] = 0;
		for (j = 0; j < i_course; j++)
		{
			f_sum[i] = f_sum[i] + score[i][j];
		}

	}

}


/**********************************
** 函数名:Calculate
** 输 入: *i_StudentNum, StudentID, score,  i_course
** *i_StudentNum---学生人数
** StudentID---学号
** score---学生成绩
** *i_course---考试科目数
** 功能描述:计算并显示课程的总分和平均分
** 作 者:坂井 离人
** 日 期:2020.11.07
** 版本:3.0.0
************************************/
void Calculate(int i_course, int i_StudentNum, long StudentID[], float score[][6])
{
	int i = 0, j = 0;
	float f_aver = 0, f_sum = 0;
	//f_aver:平均分   f_sum:总分

	for(j = 0; j < i_course; j++)
	{
		for (f_sum = 0, i = 0; i < i_StudentNum; i++)
		{
			f_sum = f_sum + score[i][j];
		}
		f_aver = f_sum / i_StudentNum;
		printf("第%d门考试总分为%.2f,平均分为%.2f\n",j+1, f_sum, f_aver);
	}


}




/**********************************
** 函数名:DescendingScore
** 输 入: *i_StudentNum, StudentID, f_sum, Rank, name, *Compare
** *i_StudentNum---学生人数
** StudentID---学号
** f_sum---学生成绩总分
** Rank---学生排名
** name---学生名字
** *Compare---比较大小的函数
** 功能描述:按成绩由高到低排出名次表
** 作 者:坂井 离人
** 日 期:2020.11.07
** 版本:3.0.0
************************************/
void DescendingScore(int i_StudentNum, float f_sum[], long StudentID[], float Rank[], int (*Compare)(float a, float b), char name[][20])
{
	int i, j, m1, m2;
	float median, fscore[30] = {0};
	char temp[30]= {0};
	char fname[30][20] = {0};

	for (i = 0; i < i_StudentNum; i++)
	{
		Rank[i] = StudentID[i];
	}
	for (i = 0; i < i_StudentNum; i++)
	{
		strcpy (fname[i], name[i]);
	}
	for (i = 0; i < i_StudentNum; i++)
	{
		fscore[i] = f_sum[i];
	}
	//首先将输入的学号顺序导入排名中
	//为的是不改变学生的学号

	for (i = 0; i < i_StudentNum; i++)
	{
		for (j = i+1; j < i_StudentNum; j++)
		{

			if ((*Compare)(fscore[i], fscore[j]) == 0)
			{
				median = Rank[i];
				Rank[i] = Rank[j];
				Rank[j] = median;
				median = fscore[i];
				fscore[i] = fscore[j];
				fscore[j] = median;
				strcpy (temp, fname[i]);
				strcpy (fname[i], fname[j]);
				strcpy (fname[j], temp);
			}
		}
	}
	//为其排序,从高到低成绩排序

	OutRank(Rank, fname, fscore, i_StudentNum, StudentID);
				//输出
}





/**********************************
** 函数名:AscendingScore
** 输 入: *i_StudentNum, StudentID, f_sum, Rank, name, *Compare
** *i_StudentNum---学生人数
** StudentID---学号
** f_sum---学生成绩总分
** Rank---学生排名
** name---学生名字
** *Compare---比较大小的函数
** 功能描述:按成绩由低到高排出名次表
** 作 者:坂井 离人
** 日 期:2020.11.07
** 版本:3.0.0
************************************/
void AscendingScore(int i_StudentNum, float f_sum[], long StudentID[], float Rank[], int (*Compare)(float a, float b), char name[][20])
{
	int i, j, m1, m2;
	float median, fscore[30] = {0};
	char temp[30]= {0};
	char fname[30][20] = {0};

	for (i = 0; i < i_StudentNum; i++)
	{
		Rank[i] = StudentID[i];
	}
	for (i = 0; i < i_StudentNum; i++)
	{
		strcpy (fname[i], name[i]);
	}
	for (i = 0; i < i_StudentNum; i++)
	{
		fscore[i] = f_sum[i];
	}
	//首先将输入的学号顺序导入排名中
	//为的是不改变学生的学号

	for (i = 0; i < i_StudentNum; i++)
	{
		for (j = i+1; j < i_StudentNum; j++)
		{

			if ((*Compare)(fscore[i], fscore[j]) == 1)
			{
				median = Rank[i];
				Rank[i] = Rank[j];
				Rank[j] = median;
				median = fscore[i];
				fscore[i] = fscore[j];
				fscore[j] = median;
				strcpy (temp, fname[i]);
				strcpy (fname[i], fname[j]);
				strcpy (fname[j], temp);
			}
		}
	}
	//为其排序,从高到低成绩排序

	OutRank(Rank, fname, fscore, i_StudentNum, StudentID);
				//输出
}
//这个程序和上面那个几乎一摸一样,只改了排序的条件




/**********************************
** 函数名:AscendingID

** 输 入: *i_StudentNum, StudentID, f_sum, Rank, name
** *i_StudentNum---学生人数
** StudentID---学号
** f_sum---学生成绩总分
** Rank---学生排名
** name---学生名字

** 功能描述:按学号由小到大排出成绩表
** 作 者:坂井 离人
** 日 期:2020.11.07
** 版本:3.0.0
************************************/
void AscendingID(int i_StudentNum, float f_sum[], long StudentID[], float Rank[], char name[][20])
{
	int i, j, m1, m2;
	float median, fscore[30] = {0};
	char temp[30]= {0};
	char fname[30][20] = {0};

	for (i = 0; i < i_StudentNum; i++)
	{
		Rank[i] = StudentID[i];
	}
	for (i = 0; i < i_StudentNum; i++)
	{
		strcpy (fname[i], name[i]);
	}
	for (i = 0; i < i_StudentNum; i++)
	{
		fscore[i] = f_sum[i];
	}
	//首先将输入的学号顺序导入排名中
	//为的是不改变学生的学号

	for (i = 0; i < i_StudentNum; i++)
	{
		for (j = i+1; j < i_StudentNum; j++)
		{

			if (Rank[i] > Rank[j])
			{
				median = Rank[i];
				Rank[i] = Rank[j];
				Rank[j] = median;
				median = fscore[i];
				fscore[i] = fscore[j];
				fscore[j] = median;
				strcpy (temp, fname[i]);
				strcpy (fname[i], fname[j]);
				strcpy (fname[j], temp);
			}
		}
	}
	//为其排序,从高到低成绩排序

	OutRank(Rank, fname, fscore, i_StudentNum, StudentID);
				//输出
}
//这个程序和上面那个几乎也一摸一样,只是将排序条件改成了学号


/**********************************
** 函数名:AscendingName
** 输 入: *i_StudentNum, StudentID, f_sum, Rank, name
** *i_StudentNum---学生人数
** StudentID---学号
** f_sum---学生成绩总分
** Rank---学生排名
** name---学生名字
** 功能描述:按姓名的字典顺序排出成绩表
** 作 者:坂井 离人
** 日 期:2020.11.07
** 版本:3.0.0
************************************/
void AscendingName(int i_StudentNum, float f_sum[], long StudentID[], float Rank[], char name[][20])
{
	int i, j, m1, m2;
	float median, fscore[30] = {0};
	char temp[30]= {0};
	char fname[30][20] = {0};

	for (i = 0; i < i_StudentNum; i++)
	{
		Rank[i] = StudentID[i];
	}
	for (i = 0; i < i_StudentNum; i++)
	{
		strcpy (fname[i], name[i]);
	}
	for (i = 0; i < i_StudentNum; i++)
	{
		fscore[i] = f_sum[i];
	}
	//首先将输入的学号顺序导入排名中
	//为的是不改变学生的学号

	for (i = 0; i < i_StudentNum; i++)
	{
		for (j = i+1; j < i_StudentNum; j++)
		{

			if (strcmp(fname[i], fname[j]) > 0)
			{
				median = Rank[i];
				Rank[i] = Rank[j];
				Rank[j] = median;
				median = fscore[i];
				fscore[i] = fscore[j];
				fscore[j] = median;
				strcpy (temp, fname[i]);
				strcpy (fname[i], fname[j]);
				strcpy (fname[j], temp);
			}
		}
	}
	//为其排序,从高到低成绩排序

	OutRank(Rank, fname, fscore, i_StudentNum, StudentID);
				//输出
}
//同上,把条件改为姓名的字典排序



/**********************************
** 函数名:Search
** 输 入: *i_StudentNum, StudentID, score, name, f_sum, i_course
** *i_StudentNum---学生人数
** StudentID---学号
** score---学生成绩
** f_sum---学生成绩总分
** i_course---考试科目数
** name---学生名字
** 功能描述:按学号查询学生排名及成绩
** 作 者:坂井 离人
** 日 期:2020.11.07
** 版本:3.0.0
************************************/
void Search(int i_StudentNum, long StudentID[], float score[][6], char name[][20], float f_sum[], int i_course)
{
	int ret, IDwant, i, j, median, R = 1;
	//IDwant:搜索的学号

	printf("Please input the StudentID you want to search:");
	ret = scanf("%ld", &IDwant);

		while (ret != 1)
		{
			while (getchar() != '\n');
			printf("Please input the StudentID you want to search:");
			ret = scanf("%ld", &IDwant);
		}

	for (i = 0; i <= i_StudentNum; i++)
	{
		if (i == i_StudentNum)
		{
			printf ("There are no students with this ID.\n");
			break;
		}//若没有输入的学号,则提示

		if (StudentID[i] == IDwant)
		{
			for (j = 0; j <= i_StudentNum; j++)
			{
				if (f_sum[j] > f_sum[i])
					R = R + 1;
			}//排名


			printf("%3.0ld %-20s第%d	", StudentID[i], name[i], R);
			for (j = 0; j < i_course; j++)
			{
				printf("%.2f	", score[i][j]);
			}
			printf("\n");
			break;

		}
	}

}






/**********************************
** 函数名:SearchName
** 输 入: *i_StudentNum, StudentID, score, name, f_sum, i_course
** *i_StudentNum---学生人数
** StudentID---学号
** score---学生成绩
** f_sum---学生成绩总分
** i_course---考试科目数
** name---学生名字
** 功能描述:按学号查询学生排名及成绩
** 作 者:坂井 离人
** 日 期:2020.11.07
** 版本:3.0.0
************************************/
void SearchName(int i_StudentNum, long StudentID[], float score[][6], char name[][20], float f_sum[], int i_course)
{
	int ret, i, j, median, R = 1;
	char  Namewant[20];
	//IDwant:搜索的学号

	printf("Please input the name you want to search:");
	scanf("%s", Namewant);

	for (i = 0; i <= i_StudentNum; i++)
	{
		if (i == i_StudentNum)
		{
			printf ("There are no students with this name.\n");

		}//若没有输入的学号,则提示

		if (strcmp(Namewant, name[i]) == 0)
		{
			for (j = 0; j <= i_StudentNum; j++)
			{
				if (f_sum[j] > f_sum[i])
					R = R + 1;
			}//排名


			printf("%3.0ld %-20s第%d	", StudentID[i], name[i], R);
			for (j = 0; j < i_course; j++)
			{
				printf("%.2f	", score[i][j]);
			}
			printf("\n");
			break;

		}
	}

}


/**********************************
** 函数名:Analysis
** 输 入: *i_StudentNum, StudentID, score, i_course
** *i_StudentNum---学生人数
** StudentID---学号
** score---学生成绩

** i_course---考试科目数

** 功能描述:按优秀（90—100分）、良好（80—89分）、中等（70—79分）、及格（60一69分）、不及格
** 作 者:坂井 离人
** 日 期:2020.11.07
** 版本:3.0.0
************************************/
void Analysis(int i_StudentNum, long StudentID[], float score[][6], int i_course)
{
	float  A = 0, B = 0, C = 0, D = 0, E = 0;
	float pA, pB, pC, pD, pE;
	int i, j;
	for (j = 0; j <i_course; j++)
	{
		for (i = 0; i < i_StudentNum; i++)
		{
			if (score[i][j] <= 100 &&score[i][j] >= 90)
				A = A + 1;
			if (score[i][j] < 90 &&score[i][j] >= 80)
				B = B + 1;
			if (score[i][j] < 80 &&score[i][j] >= 70)
				C = C + 1;
			if (score[i][j] < 70 &&score[i][j] >= 60)
				D = D + 1;
			if (score[i][j] < 60 &&score[i][j] >= 0)
				E = E + 1;
		}

		pA = A / i_StudentNum * 100;
		pB = B / i_StudentNum * 100;
		pC = C / i_StudentNum * 100;
		pD = D / i_StudentNum * 100;
		pE = E / i_StudentNum * 100;

		printf("第%d门考试:\n", j+1);

		printf("优秀人数:%.0f,占比%.2f%%\n", A, pA);
		printf("良好人数:%.0f,占比%.2f%%\n", B, pB);
		printf("中等人数:%.0f,占比%.2f%%\n", C, pC);
		printf("及格人数:%.0f,占比%.2f%%\n", D, pD);
		printf("不及格人数:%.0f,占比%.2f%%\n\n", E, pE);

		A = 0, B = 0, C = 0, D = 0, E = 0;


	}


}





/**********************************
** 函数名:Check
** 输 入:StudentID, i
** StudentID---学号
** i---第i个输入的学号
** 输出:0 or 1
** 0:表示学号没有重复
** 1:表示学号重复
** 功能描述:检测学号是否重复
** 作 者:坂井 离人
** 日 期:2020.10.31
** 版本:1.0.0
************************************/
int Check(int i, long StudentID[])
{
	int n;
	for (n = 0; n < i; n++)
		{
			if (StudentID[n] == StudentID[i])
			{
				return 1;
				break;
			}
			else
				return 0;
		}


}

/**********************************
** 函数名:Compare
** 输 入:a, b

** 输出:0 or 1
** 0:a < b
** 1:a > b
** 功能描述:比较a, b大小
** 作 者:坂井 离人
** 日 期:2020.10.31
** 版本:1.0.0
************************************/
int Compare(float a, float b)
{
	if (a < b)
	{
		return 0;

	}
	else
	{
		return 1;

	}
}


/**********************************
** 函数名:OutRank
** 输 入:Rank, name, score, i_StudentNum, StudentID
** *i_StudentNum---学生人数
** StudentID---学号
** fscore---学生成绩
** Rank---学生排名
** name---学生名字
** 功能描述:输出数据
** 作 者:坂井 离人
** 日 期:2020.11.07
** 版本:3.0.0
************************************/
void OutRank(float Rank[], char name[][20], float fscore[], int i_StudentNum, long StudentID)
{
	int i, median;
	for (i = 0; i < i_StudentNum; i++)
	{
		median = Rank[i];
		printf("%3.0f   %-20s   %.2f\n", Rank[i], name[i], fscore[i]);
	}
}
