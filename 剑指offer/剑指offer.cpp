﻿// 剑指offer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "string"
#include "vector"
using namespace std;

class Solution {
public:
/************************************************************************/
/*                                   1、二维数组中的查找
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，
判断数组中是否含有该整数。
*/
/************************************************************************/
	bool Find(int tager, vector<vector<int>> array) 
	{
		bool res = false;
		int len1 = array.size();
		int len2 = array[0].size();
		for (int i = 0; i  < len1; i++)
		{
			for (int j = 0; j < len2; j++)
			{
				if (array[i][j] == tager)
				{
					res = true;
				}
			}
		}
		return res;
	}
	bool Find1(int tager, vector<vector<int>> array)
	{
		int rowCount = array.size();
		int colCount = array[0].size();
		int i = rowCount - 1, j = 0;
		while (i >= 0 && j < colCount)
		{
			if (tager < array[i][j])
			{
				i--;
			}
			else if (tager > array[i][j])
			{
				j++;
			}
			else
				return true;
		}
		return false;
	}
	/************************************************************************/
	/*                                2、替换空格                     
	请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.
	则经过替换之后的字符串为We%20Are%20Happy。
	*/
	/************************************************************************/
	void replaceSpace(char* str, int length) {

	}
};



int main()
{
    cout << "Hello World!\n"; 
	cout << "asdfa";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
