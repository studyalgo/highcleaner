
#include <iostream>

using namespace std;

class cordinate {

public:
	int length;
	int* x = new int[length];
	int* y = new int[length];

	// �⺻ ������ 

	cordinate() {		
		std::cout << "��ǥ������ �Է��Ͻÿ�.\n";
		std::cin >> length;
		x = new int[length];
		y = new int[length];
		for (int i = 0; i < length; i++)
		{
			std::cin >> x[i] >> y[i];			
		}
	}
	void destroy(int next)
	{
		for (int i = next; i < length; i++)
		{
			if (i + 1 >= length)
			{
				x[i] = 0;
				y[i] = 0;
				break;
			}
				
			x[i] = x[i+1];
			y[i] = y[i + 1];
		}
	}
	
	void sort(int pre, int next)
	{
		int tempX = 0;
		int tempY = 0;		

		tempY = y[pre];
		y[pre] = y[next];
		y[next] = tempY;

		tempX = x[pre];
		x[pre] = x[next];
		x[next] = tempX;
	

	}


	void check()
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = i+1; j < length; j++)
			{
				int tempX = 0;
				int tempY = 0;				
				if (y[i] > y[j])
				{										
					sort(i, j);
				}
				else if (y[i] == y[j])
				{					
					if (x[i] > x[j])
					{						
						sort(i, j);
					}
					else if (x[i] == x[j])
					{						
						destroy(j);
					}
				}
			}
		}
	}
	void print()
	{
		for (int i = 0; i < length; i++)
		{
			std::cout << x[i] << y[i]<<"\n";
		}

	}
	
};
int main()
{
	///���α׷��� �����մϴ�
	cordinate data =  cordinate();	
	data.check();
	data.print();
	std::cout << "���α׷��� �����մϴ�.";
	delete[] data.x;
	delete[] data.y;

	return 0;
}
