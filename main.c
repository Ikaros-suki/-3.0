/*************************************
**��������:���ڹ���ѧ���ɼ�
**����:2020/11/07
**��ҵ��Ŀ:StudentScoreManager
**����:choice
**���뷶Χ:0-11
**���:�������������
**����:�ྮ ����
**�汾:3.0.0
**************************************
*/



#include<stdio.h>
#include<string.h>

void Input(int *i_StudentNum, int *i_course, long StudentID[], float score[][6], char name[][20]);
//�������ݵĺ���
void Calculate(int i_course, int i_StudentNum, long StudentID[], float score[][6]);
//���㲢���ѧ���ܷ�,ƽ���ֵĺ���
void CalculateS(int i_course, float score[][6], int i);
//����ÿ�ſγ̵��ֺܷ�ƽ����
void CalculateP(int i_course, float score[][6], int i_StudentNum, float f_sum[]);
//��������ÿ��ѧ�����ֺܷ�ƽ����
int Compare(float a, float b);
//�Ƚϴ�С�ĺ���
void DescendingScore(int i_StudentNum, float f_sum[], long StudentID[], float Rank[], int (*Compare)(float a, float b), char name[][20]);
//��ÿ��ѧ�����ܷ��ɸߵ����ų����α�ĺ���
void AscendingScore(int i_StudentNum, float f_sum[], long StudentID[], float Rank[], int (*Compare)(float a, float b), char name[][20]);
//��ÿ��ѧ�����ܷ��ɵ͵����ų����α�ĺ���
void AscendingID(int i_StudentNum, float f_sum[], long StudentID[], float Rank[], char name[][20]);
//��ѧ����С�����ų��ɼ���ĺ���
void Search(int i_StudentNum, long StudentID[], float score[][6], char name[][20], float f_sum[], int i_course);
//��ѧ�Ų�ѯѧ������������ƿ��Գɼ��ĺ���
void Analysis(int i_StudentNum, long StudentID[], float score[][6], int i_course);
//��ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�İٷֱȵĺ���
int Check(int i, long StudentID[]);
//ѧ�Ų��غ���
void OutRank(float Rank[], char name[][20], float fscore[], int i_StudentNum, long StudentID);
//�������
void AscendingName(int i_StudentNum, float f_sum[], long StudentID[], float Rank[], char name[][20]);
//���������ֵ�˳���ų��ɼ���ĺ���
void SearchName(int i_StudentNum, long StudentID[], float score[][6], char name[][20], float f_sum[], int i_course);
//.��������ѯѧ������������ƿ��Գɼ��ĺ���

//��Ϊÿ����Ҫ�������ֵĵط��������˼���������Ƿ�Ϊ���ֵ����

main()
{
	//һ��ѱ���,�ں������ֻ����������������˼
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
	//��ӡѡ��


	do{
		scanf("%d%*c", &choice);
		//�û�����ѡ��


		switch (choice)//�����û���ѡ����ò�ͬ�ĺ���
		{
			case 1:
				Input(&pi_StudentNum, &pi_course, StudentID, score, name);
				printf("Please enter your choice:");
				CalculateP(pi_course, score, pi_StudentNum, f_sum);
				while(getchar() != '\n');
				break;
				//��1֮ǰ��������ѧ������
				//1:¼��ѧ��ѧ�źͿ��Գɼ�

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
				//���ÿ��ѧ����ѧ�źͿ��Գɼ�(�������˳��)(�൱�ڸ�����)

			case 3:
				if(pi_StudentNum == 0)
					Input(&pi_StudentNum,&pi_course, StudentID, score, name);
                printf("ÿ�ſγ̵��ֺܷ�ƽ��������:\n");
				Calculate(pi_course, pi_StudentNum, StudentID, score);
				printf("\n");
				printf("Please enter your choice:");
				break;
				// ����ÿ�ſγ̵��ֺܷ�ƽ����

			case 4:
				if(pi_StudentNum == 0)
					Input(&pi_StudentNum,&pi_course, StudentID, score, name);

                printf("ÿ��ѧ�����ֺܷ�ƽ��������:\n");
				for (i = 0; i < pi_StudentNum; i++)
					{
						printf("%3ld   %-20s   ", StudentID[i], name[i]);

						CalculateS(pi_course, score, i);
						printf("\n");
					}
				printf("Please enter your choice:");
				break;
				//����ÿ��ѧ�����ֺܷ�ƽ����

			case 5:
				if(pi_StudentNum == 0)
					Input(&pi_StudentNum,&pi_course, StudentID, score, name);
				CalculateP(pi_course, score, pi_StudentNum, f_sum);
				printf("���ɼ��ɸߵ���������:\n");
				DescendingScore(pi_StudentNum, f_sum, StudentID, Rank, Compare, name);
				printf("\n");


				printf("Please enter your choice:");
				break;
				//���ɼ��ɸߵ����ų����α�


			case 6:
				if(pi_StudentNum == 0)
					Input(&pi_StudentNum,&pi_course, StudentID, score, name);
				CalculateP(pi_course, score, pi_StudentNum, f_sum);
				printf("���ɼ��ɵ͵���������:\n");
				AscendingScore(pi_StudentNum, f_sum, StudentID, Rank, Compare, name);
				printf("\n");
				printf("Please enter your choice:");
				break;
				//���ɼ��ɵ͵����ų����α�

			case 7:
				if(pi_StudentNum == 0)
					Input(&pi_StudentNum,&pi_course, StudentID, score, name);
				CalculateP(pi_course, score, pi_StudentNum, f_sum);
				printf("��ѧ����С����������:\n");
				AscendingID(pi_StudentNum, f_sum, StudentID, Rank, name);
				printf("\n");
				printf("Please enter your choice:");
				break;
				//��ѧ����С�����ų��ɼ���

			case 8:
				if(pi_StudentNum == 0)
					Input(&pi_StudentNum,&pi_course, StudentID, score, name);
				CalculateP(pi_course, score, pi_StudentNum, f_sum);
				printf("���������ֵ�˳��������:\n");
				AscendingName(pi_StudentNum, f_sum, StudentID, Rank, name);
				printf("Please enter your choice:");
				printf("\n");
				break;
				//���������ֵ�˳���ų��ɼ���


			case 9:
				if(pi_StudentNum == 0)
					Input(&pi_StudentNum,&pi_course, StudentID, score, name);
				CalculateP(pi_course, score, pi_StudentNum, f_sum);
				Search(pi_StudentNum, StudentID, score, name, f_sum, pi_course);
				printf("Please enter your choice:");
				printf("\n");
				while(getchar() != '\n');
				break;
				//��ѧ�Ų�ѯѧ���������ɼ�

			case 10:
				if(pi_StudentNum == 0)
					Input(&pi_StudentNum,&pi_course, StudentID, score, name);
				CalculateP(pi_course, score, pi_StudentNum, f_sum);
				SearchName(pi_StudentNum, StudentID, score, name, f_sum, pi_course);
				printf("Please enter your choice:");
				printf("\n");
				while(getchar() != '\n');
				break;
				//��������ѯѧ���������俼�Գɼ�


			case 11:
				if(pi_StudentNum == 0)
					Input(&pi_StudentNum,&pi_course, StudentID, score, name);
				Analysis(pi_StudentNum, StudentID, score, pi_course);
				printf("Please enter your choice:");
				printf("\n");
				while(getchar() != '\n');
				break;
				/*�����㣨90��100�֣������ã�80��89�֣����еȣ�70��79�֣�������60һ69�֣���������
					(0��59��)5�����ͳ��ÿ�����������Լ���ռ�İٷֱ�*/

			case 0:
				break;
				//�˳�����

			default:
				printf("\n");
				printf("Please enter your choice:");
				break;
				//������Ĳ���0-11���ַ�,���ٴ�����
		}


	}while (choice != 0);


}

/**********************************
** ������:Input
** �� ��: *i_StudentNum, StudentID, score, name, *i_course
** *i_StudentNum---ѧ������
** StudentID---ѧ��
** score---ѧ���ɼ�
** name---ѧ������
** *i_course---���Կ�Ŀ��
** ��������:ȷ��ѧ�������Լ�¼��ѧ��ѧ�źͶ�Ӧ��ѧ���ɼ�
** �� ��:�ྮ ����
** �� ��:2020.11.07
** �汾:3.0.0
************************************/
void Input(int *i_StudentNum, int *i_course, long StudentID[], float score[][6], char name[][20])
{
	int ret = 0, i = 0 ,n, check = 0, j = 0;

	for ( ; *i_StudentNum < 1 || *i_StudentNum > 30; )
	{
		//��Ϊ����������,�Ҷ���*i_StudentNumΪ0,���Գ���ʼʱ��ִ��
		//�������ѧ��������������1-30֮��,����������
		printf("������ѧ������(1-30):");
		ret = scanf("%d", &*i_StudentNum);

		while (ret != 1)
		{
			while (getchar() != '\n');
			printf("������ѧ������(1-30):");
			ret = scanf("%d", &*i_StudentNum);

		}
	}

	for ( ; *i_course < 1 || *i_course > 6; )
	{
		//��Ϊ����������,�Ҷ���*i_StudentNumΪ0,���Գ���ʼʱ��ִ��
		//�������ѧ��������������1-30֮��,����������
		printf("�������Ŀ��(1-6):");
		ret = scanf("%d", &*i_course);

		while (ret != 1)
		{
			while (getchar() != '\n');
			printf("�������Ŀ��(1-6):");
			ret = scanf("%d", &*i_course);

		}
	}

	for (i = 0; i < *i_StudentNum; i++)
	{

		//ִ��ֱ��������������ѧ��������*i_StudentNum
		printf("������ѧ��:");
		ret = scanf("%d", &StudentID[i]);
			check = Check(i, StudentID);
			//Check�������ڼ���ѧ���Ƿ��ظ�
		while (ret != 1 || check == 1)
		{
			while (getchar() != '\n');
			printf("������ѧ��:");
			ret = scanf("%ld", &StudentID[i]);
			check = Check(i, StudentID);
		}

		for (n = 0; n < i; n++)
		{
			if (StudentID[n] == StudentID[i])
			{
				while (getchar() != '\n');
				printf("������ѧ��:");
				scanf("%ld", &StudentID[i]);

			}
		}

		while (getchar() != '\n');
		printf("������ѧ������:");
		gets(name[i]);
		//¼��ѧ��������������ѧ�Ŷ�Ӧ

		for (j = 0; j < *i_course; j++)
		{
			printf("�������ѧ����%d�ſ��Գɼ�:", j+1);
			ret = scanf("%f", &score[i][j]);
			//���ɼ�С��0�����100,����������
			while (ret != 1 || score[i][j] < 0 || score[i][j] >100)
			{
				while (getchar() != '\n');
				printf("�������ѧ���ɼ�:");
				ret = scanf("%f", &score[i][j]);
			}
		}


	}
}

/**********************************
** ������:CalculateS
** �� ��:score, i, *i_course

** score---ѧ���ɼ�
** i---ĳ��ѧ��
** *i_course---���Կ�Ŀ��
** ��������:���㲢���ѧ���ֺܷ�ƽ����
** �� ��:�ྮ ����
** �� ��:2020.11.07
** �汾:3.0.0
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
	printf("�ܷ�Ϊ%.2f,ƽ����Ϊ%.2f\n", f_sum, f_aver);
}


/**********************************
** ������:CalculateP
** �� ��: *i_StudentNum, score, *i_course, f_sum
** *i_StudentNum---ѧ������

** score---ѧ���ɼ�
** f_sum---ѧ���ܷ�
** *i_course---���Կ�Ŀ��
** ��������:��������ѧ���ܷ�
** �� ��:�ྮ ����
** �� ��:2020.11.07
** �汾:3.0.0
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
** ������:Calculate
** �� ��: *i_StudentNum, StudentID, score,  i_course
** *i_StudentNum---ѧ������
** StudentID---ѧ��
** score---ѧ���ɼ�
** *i_course---���Կ�Ŀ��
** ��������:���㲢��ʾ�γ̵��ֺܷ�ƽ����
** �� ��:�ྮ ����
** �� ��:2020.11.07
** �汾:3.0.0
************************************/
void Calculate(int i_course, int i_StudentNum, long StudentID[], float score[][6])
{
	int i = 0, j = 0;
	float f_aver = 0, f_sum = 0;
	//f_aver:ƽ����   f_sum:�ܷ�

	for(j = 0; j < i_course; j++)
	{
		for (f_sum = 0, i = 0; i < i_StudentNum; i++)
		{
			f_sum = f_sum + score[i][j];
		}
		f_aver = f_sum / i_StudentNum;
		printf("��%d�ſ����ܷ�Ϊ%.2f,ƽ����Ϊ%.2f\n",j+1, f_sum, f_aver);
	}


}




/**********************************
** ������:DescendingScore
** �� ��: *i_StudentNum, StudentID, f_sum, Rank, name, *Compare
** *i_StudentNum---ѧ������
** StudentID---ѧ��
** f_sum---ѧ���ɼ��ܷ�
** Rank---ѧ������
** name---ѧ������
** *Compare---�Ƚϴ�С�ĺ���
** ��������:���ɼ��ɸߵ����ų����α�
** �� ��:�ྮ ����
** �� ��:2020.11.07
** �汾:3.0.0
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
	//���Ƚ������ѧ��˳����������
	//Ϊ���ǲ��ı�ѧ����ѧ��

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
	//Ϊ������,�Ӹߵ��ͳɼ�����

	OutRank(Rank, fname, fscore, i_StudentNum, StudentID);
				//���
}





/**********************************
** ������:AscendingScore
** �� ��: *i_StudentNum, StudentID, f_sum, Rank, name, *Compare
** *i_StudentNum---ѧ������
** StudentID---ѧ��
** f_sum---ѧ���ɼ��ܷ�
** Rank---ѧ������
** name---ѧ������
** *Compare---�Ƚϴ�С�ĺ���
** ��������:���ɼ��ɵ͵����ų����α�
** �� ��:�ྮ ����
** �� ��:2020.11.07
** �汾:3.0.0
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
	//���Ƚ������ѧ��˳����������
	//Ϊ���ǲ��ı�ѧ����ѧ��

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
	//Ϊ������,�Ӹߵ��ͳɼ�����

	OutRank(Rank, fname, fscore, i_StudentNum, StudentID);
				//���
}
//�������������Ǹ�����һ��һ��,ֻ�������������




/**********************************
** ������:AscendingID

** �� ��: *i_StudentNum, StudentID, f_sum, Rank, name
** *i_StudentNum---ѧ������
** StudentID---ѧ��
** f_sum---ѧ���ɼ��ܷ�
** Rank---ѧ������
** name---ѧ������

** ��������:��ѧ����С�����ų��ɼ���
** �� ��:�ྮ ����
** �� ��:2020.11.07
** �汾:3.0.0
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
	//���Ƚ������ѧ��˳����������
	//Ϊ���ǲ��ı�ѧ����ѧ��

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
	//Ϊ������,�Ӹߵ��ͳɼ�����

	OutRank(Rank, fname, fscore, i_StudentNum, StudentID);
				//���
}
//�������������Ǹ�����Ҳһ��һ��,ֻ�ǽ����������ĳ���ѧ��


/**********************************
** ������:AscendingName
** �� ��: *i_StudentNum, StudentID, f_sum, Rank, name
** *i_StudentNum---ѧ������
** StudentID---ѧ��
** f_sum---ѧ���ɼ��ܷ�
** Rank---ѧ������
** name---ѧ������
** ��������:���������ֵ�˳���ų��ɼ���
** �� ��:�ྮ ����
** �� ��:2020.11.07
** �汾:3.0.0
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
	//���Ƚ������ѧ��˳����������
	//Ϊ���ǲ��ı�ѧ����ѧ��

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
	//Ϊ������,�Ӹߵ��ͳɼ�����

	OutRank(Rank, fname, fscore, i_StudentNum, StudentID);
				//���
}
//ͬ��,��������Ϊ�������ֵ�����



/**********************************
** ������:Search
** �� ��: *i_StudentNum, StudentID, score, name, f_sum, i_course
** *i_StudentNum---ѧ������
** StudentID---ѧ��
** score---ѧ���ɼ�
** f_sum---ѧ���ɼ��ܷ�
** i_course---���Կ�Ŀ��
** name---ѧ������
** ��������:��ѧ�Ų�ѯѧ���������ɼ�
** �� ��:�ྮ ����
** �� ��:2020.11.07
** �汾:3.0.0
************************************/
void Search(int i_StudentNum, long StudentID[], float score[][6], char name[][20], float f_sum[], int i_course)
{
	int ret, IDwant, i, j, median, R = 1;
	//IDwant:������ѧ��

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
		}//��û�������ѧ��,����ʾ

		if (StudentID[i] == IDwant)
		{
			for (j = 0; j <= i_StudentNum; j++)
			{
				if (f_sum[j] > f_sum[i])
					R = R + 1;
			}//����


			printf("%3.0ld %-20s��%d	", StudentID[i], name[i], R);
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
** ������:SearchName
** �� ��: *i_StudentNum, StudentID, score, name, f_sum, i_course
** *i_StudentNum---ѧ������
** StudentID---ѧ��
** score---ѧ���ɼ�
** f_sum---ѧ���ɼ��ܷ�
** i_course---���Կ�Ŀ��
** name---ѧ������
** ��������:��ѧ�Ų�ѯѧ���������ɼ�
** �� ��:�ྮ ����
** �� ��:2020.11.07
** �汾:3.0.0
************************************/
void SearchName(int i_StudentNum, long StudentID[], float score[][6], char name[][20], float f_sum[], int i_course)
{
	int ret, i, j, median, R = 1;
	char  Namewant[20];
	//IDwant:������ѧ��

	printf("Please input the name you want to search:");
	scanf("%s", Namewant);

	for (i = 0; i <= i_StudentNum; i++)
	{
		if (i == i_StudentNum)
		{
			printf ("There are no students with this name.\n");

		}//��û�������ѧ��,����ʾ

		if (strcmp(Namewant, name[i]) == 0)
		{
			for (j = 0; j <= i_StudentNum; j++)
			{
				if (f_sum[j] > f_sum[i])
					R = R + 1;
			}//����


			printf("%3.0ld %-20s��%d	", StudentID[i], name[i], R);
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
** ������:Analysis
** �� ��: *i_StudentNum, StudentID, score, i_course
** *i_StudentNum---ѧ������
** StudentID---ѧ��
** score---ѧ���ɼ�

** i_course---���Կ�Ŀ��

** ��������:�����㣨90��100�֣������ã�80��89�֣����еȣ�70��79�֣�������60һ69�֣���������
** �� ��:�ྮ ����
** �� ��:2020.11.07
** �汾:3.0.0
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

		printf("��%d�ſ���:\n", j+1);

		printf("��������:%.0f,ռ��%.2f%%\n", A, pA);
		printf("��������:%.0f,ռ��%.2f%%\n", B, pB);
		printf("�е�����:%.0f,ռ��%.2f%%\n", C, pC);
		printf("��������:%.0f,ռ��%.2f%%\n", D, pD);
		printf("����������:%.0f,ռ��%.2f%%\n\n", E, pE);

		A = 0, B = 0, C = 0, D = 0, E = 0;


	}


}





/**********************************
** ������:Check
** �� ��:StudentID, i
** StudentID---ѧ��
** i---��i�������ѧ��
** ���:0 or 1
** 0:��ʾѧ��û���ظ�
** 1:��ʾѧ���ظ�
** ��������:���ѧ���Ƿ��ظ�
** �� ��:�ྮ ����
** �� ��:2020.10.31
** �汾:1.0.0
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
** ������:Compare
** �� ��:a, b

** ���:0 or 1
** 0:a < b
** 1:a > b
** ��������:�Ƚ�a, b��С
** �� ��:�ྮ ����
** �� ��:2020.10.31
** �汾:1.0.0
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
** ������:OutRank
** �� ��:Rank, name, score, i_StudentNum, StudentID
** *i_StudentNum---ѧ������
** StudentID---ѧ��
** fscore---ѧ���ɼ�
** Rank---ѧ������
** name---ѧ������
** ��������:�������
** �� ��:�ྮ ����
** �� ��:2020.11.07
** �汾:3.0.0
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
