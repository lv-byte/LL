#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int a, b, d, t;    //定义两个操作数a,b，结果d，输入结果t
	char c;         //运算符c可取“＋、－、×、÷”
	int i, sum = 0;    //题目数量i,答对数目sum
	srand(time(0)); //初始化随机数发生器
	for (i = 0; i < 10; i++)
	{
		a = rand() % 100 + 1;
		b = rand() % 100 + 1;
		c = rand() % 4;     //0表加，1表减，2表乘，3表除

		/**< 数据合格判断及算式显示 */
		printf("第%d题：", i + 1);
		switch (c)
		{
		case 0:
			while ((d = a + b) > 100)    //保证和在100内
			{
				a = rand() % 100 + 1;
				b = rand() % 100 + 1;
			}
			printf("%d + %d = ", a, b);
			break;
		case 1:
			while (a > 100 || b > 100) //被减数小于100
			{
				a = rand() % 100 + 1;
				b = rand() % 100 + 1;
			}
			if (a < b)             //被减数大于减数
			{
				d = a;
				a = b;
				b = d;
			}
			d = a - b;
			printf("%d - %d = ", a, b);
			break;
		case 2:
			while ((d = a * b) > 100)    //保证积小于100
			{
				a = rand() % 100 + 1;
				b = rand() % 100 + 1;
			}
			printf("%d × %d = ", a, b);
				
			break;
		case 3:
			while (a > 100 || b > 100 || (a * b == 0))   //保证被除数小于100且除数不为0
			{
				a = rand() % 100 + 1;
				b = rand() % 100 + 1;
			}
			if (a < b)           //被除数必须大于除数
			{
				d = a;
				a = b;
				b = d;
			}
			a = (a / b) * b;      //保证整除
			d = a / b;
			printf("%d ÷ %d = ", a, b);
			break;
		}
		/**< 输入你的计算结果 */
		scanf("%d", &t);
		if (d == t)
		{
			sum++;
			printf("正确\n");
		}
		else
			printf("错误\n");

	}
	/**< 输出答对题数和得分 */
	printf("答对 %d 题，得分：%d\n", sum, sum * 10);
	return 0;
	
}
