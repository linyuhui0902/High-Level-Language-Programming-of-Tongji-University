/*2553725 ÁÖÓÚÞ¥ ×¿11*/
#include<iostream>
using namespace std;

int main()
{
	double a;
	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:" << endl;
	cin >> a;
	cout << "´óÐ´½á¹ûÊÇ:" << endl;
	int a1 = static_cast<int>(a / 10);
	switch (a1 / 100000000) {
		case 9:
			cout << "¾ÁÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;
		case 5:
			cout << "ÎéÊ°";
			break;
		case 4:
			cout << "ËÁÊ°";
			break;
		case 3:
			cout << "ÈþÊ°";
			break;
		case 2:
			cout << "·¡Ê°";
			break;
		case 1:
			cout << "Ò¼Ê°";
			break;
		}
	switch (a1 / 10000000 % 10) {
		case 9:
			cout << "¾ÁÒÚ";
			break;
		case 8:
			cout << "°ÆÒÚ";
			break;
		case 7:
			cout << "ÆâÒÚ";
			break;
		case 6:
			cout << "Â½ÒÚ";
			break;
		case 5:
			cout << "ÎéÒÚ";
			break;
		case 4:
			cout << "ËÁÒÚ";
			break;
		case 3:
			cout << "ÈþÒÚ";
			break;
		case 2:
			cout << "·¡ÒÚ";
			break;
		case 1:
			cout << "Ò¼ÒÚ";
			break;
		case 0:
			if (a1/ 100000000 != 0) {
				cout << "ÒÚ";
			}
			break;
		}                            //Ê°ÒÚ~ÒÚ
	switch (a1 / 1000000 % 10) {
	    case 9:
			cout << "¾ÁÇª";
			break;
		case 8:
			cout << "°ÆÇª";
			break;
		case 7:
			cout << "ÆâÇª";
			break;
		case 6:
			cout << "Â½Çª";
			break;
		case 5:
			cout << "ÎéÇª";
			break;
		case 4:
			cout << "ËÁÇª";
			break;
		case 3:
			cout << "ÈþÇª";
			break;
		case 2:
			cout << "·¡Çª";
			break;
		case 1:
			cout << "Ò¼Çª";
			break;
		case 0:
			if (a1/10000000!=0 &&(a1 / 100000 % 10 != 0 || a1 / 10000 % 10 !=0 || a1/ 1000 % 10 !=0)) {
				cout << "Áã";
			}
			break;
		}
	switch (a1 / 100000 % 10) {
		case 9:
			cout << "¾Á°Û";
			break;
		case 8:
			cout << "°Æ°Û";
			break;
		case 7:
			cout << "Æâ°Û";
			break;
		case 6:
			cout << "Â½°Û";
			break;
		case 5:
			cout << "Îé°Û";
			break;
		case 4:
			cout << "ËÁ°Û";
			break;
		case 3:
			cout << "Èþ°Û";
			break;
		case 2:
			cout << "·¡°Û";
			break;
		case 1:
			cout << "Ò¼°Û";
			break;
		case 0:
			if (a1/1000000%10!=0 && (a1 / 10000 % 10 != 0 || a1 / 1000 % 10 != 0)) {
				cout << "Áã";
			}
			break;
		}
	switch (a1 / 10000 % 10) {
		case 9:
			cout << "¾ÁÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;	   
		case 5:		   
			cout << "ÎéÊ°";
			break;	   
		case 4:		   
			cout << "ËÁÊ°";
			break;	   
		case 3:		   
			cout << "ÈþÊ°";
			break;	   
		case 2:		   
			cout << "·¡Ê°";
			break;	   
		case 1:		   
			cout << "Ò¼Ê°";
			break;
		case 0:
			if (a1/100000%10!=0 && a1/1000 % 10 != 0) {
				cout << "Áã";
			}
			break;
		}
	switch (a1 / 1000 % 10) {
		case 9:
			cout << "¾ÁÍò";
			break;
		case 8:
			cout << "°ÆÍò";
			break;
		case 7:
			cout << "ÆâÍò";
			break;
		case 6:
			cout << "Â½Íò";
			break;
		case 5:
			cout << "ÎéÍò";
			break;
		case 4:
			cout << "ËÁÍò";
			break;
		case 3:
			cout << "ÈþÍò";
			break;
		case 2:
			cout << "·¡Íò";
			break;
		case 1:
			cout << "Ò¼Íò";
			break;
		case 0:
			if (a1/10000%10!=0||a1/100000%10!=0||a1/1000000%10!=0) {
				cout << "Íò";
			}
			break;
		}                               //ÇªÍò~Íò
	switch (a1 / 100 % 10) {
		case 9:
			cout << "¾ÁÇª";
			break;
		case 8:
			cout << "°ÆÇª";
			break;
		case 7:
			cout << "ÆâÇª";
			break;
		case 6:
			cout << "Â½Çª";
			break;
		case 5:
			cout << "ÎéÇª";
			break;
		case 4:
			cout << "ËÁÇª";
			break;
		case 3:
			cout << "ÈþÇª";
			break;
		case 2:
			cout << "·¡Çª";
			break;
		case 1:
			cout << "Ò¼Çª";
			break;
		case 0:
			if (a1 / 1000 != 0 && (a1 / 10 % 10 != 0 || a1 % 10 != 0 ||
				static_cast<int>((a/10 - a1 + 0.0001) / 0.1) % 10 != 0)) {
				cout << "Áã";
			}
			break;
		}
	switch (a1 / 10 % 10) {
	   case 9:
		    cout << "¾Á°Û";
		    break;
	   case 8:
		    cout << "°Æ°Û";
		    break;
	   case 7:
		    cout << "Æâ°Û";
		    break;
	   case 6:
		    cout << "Â½°Û";
		    break;
	   case 5:
		    cout << "Îé°Û";
		    break;
	   case 4:
		    cout << "ËÁ°Û";
		    break;
	   case 3:
		    cout << "Èþ°Û";
		    break;
	   case 2:
		    cout << "·¡°Û";
		    break;
	   case 1:
		    cout << "Ò¼°Û";
		    break;
	   case 0:
		    if (a1 / 100 % 10 != 0 &&(a1 % 10 != 0 || static_cast<int>((a/10 - a1 + 0.0001) / 0.1) % 10 != 0)) {
			    cout << "Áã";
		    }
		    break;
	}
	switch (a1 % 10) {
	   case 9:
		    cout << "¾ÁÊ°";
		    break;
	   case 8:
		    cout << "°ÆÊ°";
		    break;
	   case 7:
		    cout << "ÆâÊ°";
		    break;
	   case 6:
		    cout << "Â½Ê°";
		    break;
	   case 5:
		    cout << "ÎéÊ°";
		    break;
	   case 4:
		    cout << "ËÁÊ°";
		    break;
	   case 3:
		    cout << "ÈþÊ°";
		    break;
	   case 2:
		    cout << "·¡Ê°";
		    break;
	   case 1:
		    cout << "Ò¼Ê°";
		    break;
	   case 0:
		    if (a1/10 % 10 != 0 && static_cast<int>((a/10 - a1 + 0.0001) / 0.1) % 10 != 0) {
			    cout << "Áã";
		    }
		    break;
	}
	switch (static_cast<int>((a/10-a1+0.0001)/0.1)%10) {
	   case 9:
		    cout << "¾ÁÔ²";
		    break;
	   case 8:
		    cout << "°ÆÔ²";
		    break;
	   case 7:
		    cout << "ÆâÔ²";
		    break;
	   case 6:
		    cout << "Â½Ô²";
		    break;
       case 5:
		    cout << "ÎéÔ²";
		    break;
	   case 4:
		    cout << "ËÁÔ²";
		    break;
	   case 3:
		    cout << "ÈþÔ²";
		    break;
	   case 2:
		    cout << "·¡Ô²";
		    break;
	   case 1:
		    cout << "Ò¼Ô²";
		    break;
	   case 0:
		    if(a1!=0){
			    cout << "Ô²";
		    }
		break;
	}                               //Çª~Ôª
	switch (static_cast<int>((a/10 - a1 + 0.0001) / 0.01) % 10) {
	   case 9:
		    cout << "¾Á½Ç";
		    break;
	   case 8:
		    cout << "°Æ½Ç";
		    break;
	   case 7:
		    cout << "Æâ½Ç";
		    break;
	   case 6:
		    cout << "Â½½Ç";
		    break;
	   case 5:
		    cout << "Îé½Ç";
		    break;
	   case 4:
		    cout << "ËÁ½Ç";
		    break;
	   case 3:
		    cout << "Èþ½Ç";
		    break;
	   case 2:
		    cout << "·¡½Ç";
		    break;
	   case 1:
		    cout << "Ò¼½Ç";
		    break;
	   case 0:
		   if ((a1!=0|| static_cast<int>((a / 10 - a1 + 0.0001) / 0.1) % 10!= 0)&& 
			   static_cast<int>((a / 10 - a1 + 0.0001) / 0.001) % 10!=0) {
			   cout << "Áã";
		   }
	}
	switch (static_cast<int>((a/10 - a1 + 0.0001) / 0.001) % 10) {
	   case 9:
		    cout << "¾Á·Ö" ;
			break;
	   case 8:
		    cout << "°Æ·Ö";
			break;
	   case 7:
		    cout << "Æâ·Ö";
			break;
	   case 6:
		    cout << "Â½·Ö";
			break;
	   case 5:
		    cout << "Îé·Ö";
			break;
	   case 4:
		    cout << "ËÁ·Ö";
			break;
	   case 3:
		    cout << "Èþ·Ö";
			break;
	   case 2:
		    cout << "·¡·Ö";
			break;
	   case 1:
		    cout << "Ò¼·Ö";
			break;
	   case 0:
		    if (a1==0 && static_cast<int>((a/10 - a1 + 0.0001) / 0.1) % 10 == 0&&
			    static_cast<int>((a /10- a1 + 0.0001) / 0.01) % 10 ==0) {
			    cout << "ÁãÔ²Õû";
		    }
		    else {
				cout << "Õû";
			}
		    break;
	}                               //½Ç~·Ö
	cout << endl;
	return 0;
}