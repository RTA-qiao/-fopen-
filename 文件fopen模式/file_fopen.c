#include <stdio.h>
#include <windows.h>
struct student {
    char name[20];          //20���ֽ�
    int age;                //4 ���ֽ�             //����ֽڵı�����Ϊ�ֽڶ���
    float score;            //2 ���ֽ� 
};
int main(void)
{
    struct student s[3] = { "zhangsan",20,96.5f,
        "����",19,98.5f ,
        "����",23,78.6f};
    FILE* pf;
    //fopen_s������һ����������һ��ָ���ļ�ָ���ָ��;
    errno_t err = fopen_s(&pf,"test.txt", "wb+");
    if (err)
    {
        printf("Error!!");
        return 0;
    }
    //  ���������ļ��д�������������������Ӧ��count��д��2                                                           // ͬ����ҲӦ�ö����������߽ṹ�����飬���ڴ����ʱ��

    //����ֱ�������������䵱ָ��   

//                                                        �������ȡ���������� fread Ҳ����ͬ�ĵ���

    //������һ����������Ҫд��Ŀ�������ݵĵ�ַvoid * ���ͣ��������κ����͵�ַ
    //�ڶ�������д����ֽ�����ÿ��д���ļ���ָ�붼������ƶ����ڶ���������������ƶ����ֽ���
    //����������������ƶ����ٴ�count   ������
    //���ĸ�������ָ���ļ���ָ��
    fwrite(s, sizeof(struct student), 3, pf);
    //rewind�������ļ�ָ���ƶ����ļ����ײ�
    rewind(pf);
    struct student s1;
    //��ȡ������ֽ� ��ȡ���ٴ�
    fread(&s1, sizeof(struct student), 1, pf);
    printf("%s %d %.2f\n", s1.name, s1.age, s1.score);

    //fread����
    /*
        ��һ�����������ļ���洢�ĵ�ַ
        �ڶ��������������ֽ���
        ���������������Ĵ���
        ���ĸ�����Ҫ�������ļ�ָ��
    */
    fread(&s1, sizeof(struct student), 1, pf);
    printf("%s %d %.2f\n", s1.name, s1.age, s1.score);
    printf("pf�ļ����ĵ�ַΪ %p\n", pf);
    char* pch = (char*)pf;
    printf("pch �ĵ�ַ Ϊ%p\n", pch);
    printf("%c\n", *pch);
    printf("%zd\n", sizeof(struct student));
    fclose(pf);
}
