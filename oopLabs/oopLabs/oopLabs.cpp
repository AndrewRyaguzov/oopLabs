#include "pch.h"
#include <iostream>
#include "classMatrix.h"
#include "classLegacyMatrix.h"
#include "classLegacyPrMatrix.h"	

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
	
	int x12[]=
	{ 
		 -4, -2, -7, 8,
		 2,  7,  4, 9,
		 2,  0,  6, -3 
	};
	

	object_1.setOrder(4);
	object_1.inputMatrix(x16_2);


	classMatrix object_2(2, x4);
	classMatrix object_3(3, x9);
	classMatrix object_4(4, x16_2);


	classMatrix objectOut_1;
	classMatrix objectOut_2;
	classMatrix objectOut_3;

	int trig;
	bool triger = true;

	while ( triger )
	{
		cout << "----------menu------------" << endl
			<< " 1 - create matrix " << endl
			<< " 2 - traspon " << endl
			<< " 3 - deter " << endl
			<< " 4 - show " << endl << endl
			<< " 5 - operator + " << endl
			<< " 6 - operator = " << endl
			<< " 7 - operator () " << endl
			<< " 8 - operator [ ] " << endl << endl
			<< " 9 - cin by '>>' " << endl
			<< " 10 -cout by '<<' " << endl
			<< " 11 -write file by '>>' " << endl
			<< " 12 -read file by '<<' " << endl
			<< " 13 -write binfile " << endl
			<< " 14 -read binfile " << endl << endl
			<< " 15 -legacy 1 " << endl
			<< " 16 -legacy 2 " << endl
			<< " 0 - exit " << endl
			<< "--------------------------" << endl
			 << "put num:  ";
		cin >> trig;
		cout << "-------end of menu--------" << endl << endl;

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
			objectOut_1.showMatrix(objectOut_1.getOrder());
			objectOut_2.showMatrix(objectOut_2.getOrder());
			objectOut_3.showMatrix(objectOut_3.getOrder());

			break;
		}
		case 5:
		{
			std::cout << "-----operator plus------" << std::endl;
			cout << *(&(object_1 + object_2));
			std::cout << "--end of operator plus--" << std::endl;
			break;
		}
		case 6:
		{
			std::cout << " -----operator = -------" << std::endl;
			object_3 = object_1; // + object_2;
			cout << object_3;
			std::cout << " ---end of operator =---" << std::endl;
			break;
		}
		case 7:
		{
			cout << "------- deter by ( ) -------" << endl;
			object_1();
			object_1.showMatrixInfo(); 
			cout << "----end of deter by ( )-----" << endl;
			break;
		}
		case 8:
		{
			cout << "-------index operator-------" << endl;
			cout << " matrix[ ";
			int i, j;
			cin >> i;
			cin >> j;
			cout << " ]" << endl;
			cout << object_2[i][j] << endl;
			cout << "----end ofindex operator----" << endl;
			break;
		}
		case 9:
		{
			cout << "--------cin by '>>'---------" << endl;
			cin >> object_3;
			cout << "-----end of cin by '>>'-----" << endl;
		}
		case 10:
		{
			cout << "-------cout by '<<'---------" << endl;
			cout << object_2;
			cout << "----end of cout by '<<'-----" << endl;
			break;
		}
		case 11:
		{
			cout << "-----write file by '<<'-----" << endl;
			std::ofstream obj;
			obj << object_3;
			cout << "--end of write file by '<<'-" << endl;
			break;
		}
		case 12:
		{
			cout << "------read file by '>>'-----" << endl;
			std::ifstream obj;
		//	obj >> objectOut;
			cout << "--end of read file by '>>'--" << endl;
			break;
		}
		case 13:
		{
			cout << "-------write binfile--------" << endl;
			std::ofstream obj_of;
			obj_of.open("text files/binaryDataForClass.bin", std::ios::binary | std::ios::in | std::ios::app);

			binWrite(obj_of, object_2);
			binWrite(obj_of, object_3); 
			binWrite(obj_of, object_4);

			obj_of.close();
			cout << "----end of write binfile----" << endl;
			break;
		}
		case 14:
		{
			cout << "--------read binfile--------" << endl;
			std::ifstream obj;
			obj.open("text files/binaryDataForClass.bin", std::ios::binary | std::ios::out);

			binRead(obj, objectOut_1);
			binRead(obj, objectOut_2);
			binRead(obj, objectOut_3);

			obj.close();
			cout << "-----end of read binfile----" << endl;
			break;
		}
		case 15:
		{
			cout << "-------legacy class 1-------" << endl;
			classLegacyMatix legacyObj;
			legacyObj.setOrder(4);
			legacyObj.set();
			legacyObj.showMatrix(legacyObj.getOrder());
			cout << "---end of legacy class 1----" << endl;
			break;
		}
		case 16:
		{
			cout << "-------legacy class 2-------" << endl;
			classLegacyPrMatix legacyObj;
			legacyObj.SetColumsRows(4, 3);
			legacyObj.inputMatrix(x12);
			legacyObj.showMatrix(legacyObj.GetColums());
			cout << "---end of legacy class 2----" << endl;
			break;
		}
		case 0:
		{
			triger = false;
			break;
		}
		}

		//objectOut_1.showMatrix(objectOut_1.getOrder());
	}

	return 0;
}
