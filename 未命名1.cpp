#include <iostream>
#include <algorithm>
#include <cstring>
#include<fstream>
#define Student_number 5
#define Teacher_number 7
using namespace std;
long long i,j,k;
char output_headline[100]={"ѧ��------����----�Ա�--ѧԺ------�༶-----ƽ����----����"};
char show_headline1[200]={"ѧ��------------------����------�Ա�----------------ѧԺ--------------------�༶-----����-----2---------3-------4--------5---------6--------7---------����-------ƽ����\n"};
char Stuenden_headline[100];
char Teacher_headline[100]; 
//{"ѧ��-------����------�Ա�--ѧԺ---�༶-------����2--3--4--5--6--7-����\n"};
//ѧ���ṹ�壨����
struct Students1{
    char id[30];
    char name[30];
    char sex[20];
    char college[50];
    char st_class[30];
    long long phone;
    double sore[Teacher_number];
    double avg;
    double sum;
    
}student1[Student_number];
// ��ʦ�Ľṹ��
struct Teachers{
    
    char name[30];
    char  id[30];
    double sore[Student_number];
    char sex[20];
    
}teacher[Teacher_number];


//���ṹ������
bool cmp( Students1  &p1,Students1 &p2)
{
    if(p1.avg>p2.avg)
    {
        return 1;
    }
    else if(p1.avg==p2.avg)
    {
        if(p1.name-p2.name>0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        
    }
    else
    {
        return 0;
    }
}


int main()
{
    //����ʦ������
    FILE *p1=NULL;
   // p1=fopen("/Users/s20181105879/Desktop/teacher.txt","r");
    p1=fopen("teacher.txt","r");
    if(!p1)
    {
        printf("open fail\n");
        return 0;
    }
    fscanf(p1,"%s",Teacher_headline);
    for(i=0;i<Teacher_number;i++)
    {
        fscanf(p1,"%s %s",teacher[i].id,teacher[i].name);
        fscanf(p1,"%s",teacher[i].sex);
        for(j=0;j<Student_number;j++)
        {
            fscanf(p1,"%lf",&teacher[i].sore[j]);
        }
    }
    fclose(p1);
    
    
    
    //��ѧ������
    FILE *fp=NULL;
 //   fp=fopen("/Users/s20181105879/Desktop/student.txt","r");
    fp=fopen("student.txt","r");
    if(!fp)
    {
        printf("open fail\n");
        return 0;
    }
    fscanf(fp,"%s",Stuenden_headline);
    for(i=0;i<Student_number;i++)
    {
        fscanf(fp,"%s",student1[i].id);
        fscanf(fp,"%s",student1[i].name);
        fscanf(fp,"%s",student1[i].sex);
        fscanf(fp,"%s",student1[i].college);
        fscanf(fp,"%s",student1[i].st_class);
        fscanf(fp,"%lld",&student1[i].phone);
    }
    fclose(fp);

    
    //�Ѳ��еĴ�ָ��Ƹ�ѧ�� 
    for(j=0;j<Student_number;j++)
    {
        for(k=0;k<Teacher_number;k++)
        {
            student1[j].sore[k]=teacher[k].sore[j];
        }
    }
    
    
    
    for(i=0;i<Student_number;i++)
    {
        sort(student1[i].sore,student1[i].sore+Teacher_number);//���߸���������
        student1[i].sum=0;
        
        for(j=1;j<Teacher_number-1;j++)
        {
            student1[i].sum+=student1[i].sore[j];
        }
        student1[i].avg=student1[i].sum/(Teacher_number-2);
    }
    
    
    //�ṹ������
    sort(student1,student1+Student_number,cmp);
    
    
    
    //��Ļ��ʾ
    printf("%s\n",output_headline);
    for(i=0;i<Student_number;i++)
    {
        printf("rank %lld:\n",(i+1));
        printf("%-10s%-8s%-6s",student1[i].id,student1[i].name,student1[i].sex);
        printf("%-10s%-10s",student1[i].college,student1[i].st_class);
        printf("%-6.2f  %-10lld\n",student1[i].avg,student1[i].phone);
        printf("\n");
    }
    
    
    
    //����ļ���ʾ
    FILE *pp=NULL;
    //pp=fopen("/Users/s20181105879/Desktop/show.txt","w");
    pp=fopen("show.txt","w");
    if(!pp)
    {
        printf("open false\n");
        return 0;
    }
    fprintf(pp,"%s",show_headline1);
    for(i=0;i<Student_number;i++)
    {
        fprintf(pp,"rank %4lld:\n",i+1);
        fprintf(pp,"%-10s",student1[i].id);
        fprintf(pp,"%20s",student1[i].name);
        fprintf(pp,"%10s",student1[i].sex);
        fprintf(pp,"%30s",student1[i].college);
        fprintf(pp,"%30s",student1[i].st_class);
        for(int j=0;j<Teacher_number;j++)
        {
            fprintf(pp,"%10.2f",student1[i].sore[j]);
        }
        fprintf(pp,"%15lld",student1[i].phone);
        fprintf(pp,"%10.2f",student1[i].avg);
        fprintf(pp,"\n\n");
        
    }
    fclose(pp);
    return 0;
}

//ѧ����� 
//ѧ��------����---�Ա�--ѧԺ----�༶------����
//2018110  �񽡾�  ��    ��е      ��е����  1008611
//2018111  ����    Ů     ҽѧԺ   ����ѧ     1008612
//2018112  ����    ��      �����  �ɻ�ѧ     1008613
//2018113  ��ţ    ��     ��֪��   ��°�     1008614
//2018114  ������ ��    �ƿ�Ժ    �������  1008615
//��ʦ��� 
//���--����--�Ա�--1--2--3--4--5--6--7--8......
//110   ����    ��    72 88 69 11 28 
//111   ����    ��   32 58 99 11 22
//112   ����    ��   62 88 99 33 22 
//113   ����    ��   72 88 79 11 62 
//114   ����    Ů   72 22 99 11 22 
//115  ���    ��    22 88 29 51 72 
//116  �ξ�   ��     72 96 99 11 92 



