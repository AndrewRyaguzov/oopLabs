#include "pch.h"
#include <iostream>
#include "classMatrix.h"

using std::cout;
using std::endl;
using std::cin;


int main()
{
	classMatrix object_1;// , object_2;
	//object.inputAll();
	//object.setOrder()
	int x4[]	{4, 7,
					 6, 9};
	int x9[]{ 11, 12, 13,
			  21, 22, 23,
			  31, 32, 34 };
	int x16[]{  11, 12, 13, 14,
				21, 22, 23, 24,
				31, 32, 33, 34,
				41, 42, 43, 44 };
	int x16_2[]{ -4, -2, -7, 8,
				  2,  7,  4, 9,
				  2,  0,  6,-3,
				  6,  4,-10,-4 };
	int x16x2[][4] =
	{ 
		{ -4, -2, -7, 8 },
		{ 2,  7,  4, 9 },
		{ 2,  0,  6, -3 },
		{6,  4,-10,-4 }
	};

	object_1.setOrder(4);
	object_1.inputMatrix(x16_2);

	classMatrix object_2(4, x16);
	classMatrix object_3 = classMatrix(4, x16x2);
	//object_1.inputMatrix(x9);

	int trig;
	bool triger = true;

	while ( triger )
	{

		cout << " create matrix - 1" << endl
			<< " traspon - 2 " << endl
			<< " deter - 3 " << endl
			<< " show - 4 " << endl << endl
			<< " +  - 5 " << endl
			<< " =  = 6 " << endl
			<< " ( ) - 7 " << endl
			<< " [ ] - 8 " << endl << endl
			 << "put num:  ";
		cin >> trig;
		switch ( trig )
		{
		case 1:
		{
			object_1.inputAll();
			break;
		}
		case 2:
		{
			cout << "transpon" << endl;
			object_1.transponMatrix();
			break;
		}
		case 3:
		{
			object_1.findDeterminant();
			cout << " deter:  " << object_1.getDet() << endl << endl;
			break;
		}
		case 4:
		{
			object_1.showMatrix();
			break;
		}
		case 5:
		{
			cout << " matrix A + B = " << endl;
			cout << object_1 + object_2 << endl;
			break;
		}
		case 6:
		{
			cout << " matrix C = A + B " << endl;
			classMatrix object_3 = object_1 + object_2;
			break;
		}
		case 7:
		{
			cout << " deter by ( ) " << endl;
			object_1();
			break;
		}
		case 8:
		{
			cout << " matrix[ ";
			int n, m;
			cin >> n;
			cin >> m;
			cout << " ]" << endl;
			object_3[n][m];
			int r;
			cout << r << endl;
			break;
		}
		case 9:
		{
			cout << " cin by >> ";
			//cin >> object_3;
			cout << endl;
		}
		case 10:
			break;

		case 12:
		{
			triger = false;
			break;
		}
		}
	}

	return 0;
}
