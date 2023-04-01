#include <stdio.h>
#include <windows.h>
struct student {
    char name[20];          //20个字节
    int age;                //4 个字节             //最大字节的倍数称为字节对齐
    float score;            //2 个字节 
};
int main(void)
{
    struct student s[3] = { "zhangsan",20,96.5f,
        "李四",19,98.5f ,
        "王武",23,78.6f};
    FILE* pf;
    //fopen_s函数第一个参数传入一个指向文件指针的指针;
    errno_t err = fopen_s(&pf,"test.txt", "wb+");
    if (err)
    {
        printf("Error!!");
        return 0;
    }
    //  这里是向文件中传入了两组数据所以相应的count就写成2                                                           // 同样的也应该定义个数组或者结构体数组，而在传入的时候

    //可以直接用数组名来充当指针   

//                                                        如果想提取出多组数据 fread 也是相同的道理。

    //函数第一个参数，是要写入的块或者数据的地址void * 类型，可以是任何类型地址
    //第二个参数写入的字节数，每次写入文件的指针都会向后移动，第二个参数就是向后移动的字节数
    //第三个参数是向后移动多少次count   计数器
    //第四个参数是指向文件的指针
    fwrite(s, sizeof(struct student), 3, pf);
    //rewind函数将文件指针移动到文件的首部
    rewind(pf);
    struct student s1;
    //读取块多少字节 读取多少次
    fread(&s1, sizeof(struct student), 1, pf);
    printf("%s %d %.2f\n", s1.name, s1.age, s1.score);

    //fread函数
    /*
        第一个参数读出文件后存储的地址
        第二个参数读出的字节数
        第三个参数读出的次数
        第四个参数要读出的文件指针
    */
    fread(&s1, sizeof(struct student), 1, pf);
    printf("%s %d %.2f\n", s1.name, s1.age, s1.score);
    printf("pf文件流的地址为 %p\n", pf);
    char* pch = (char*)pf;
    printf("pch 的地址 为%p\n", pch);
    printf("%c\n", *pch);
    printf("%zd\n", sizeof(struct student));
    fclose(pf);
}
