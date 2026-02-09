 #include <bits/stdc++.h>

using namespace std;

int main() {

	int n, v = 0, s, m = 101, f = 0, h = 0, l8, q, g1 = 0;

	int l = 0;

	bool flag = false;

	cout << "系统将随机生成一个1到100的数";

	srand(time(NULL));

	n = rand() % 100 + 1;

	srand(time(NULL));

	l8 = rand();
	
//	cout << l8; cout << n;  //检测代码// 犯规保护


	while (!flag) {

		cout << endl << "请输入一个数:";

		cin >> s;

		if (s > n) {

			if (s >= m || s <= v) {



				/*		for (int i = 0; i <= 1110; i++) {           //31-43的批注别乱开

							if (i > 99  &&  l <= 1000) {

								i = 0;

								l++;

							}

						*/	cout << "你犯规了！！！   ";
				/*	cin >> q;
					if (g1 == 0) {
						g1++;
						if (q == l8) {
							continue;
						} else {
							return 0;
						}

					} else {*/
				return 0;
				//	}




//				}



			}

			cout << "太大了，在 " << v  << " 和 " << s << " 之间";


			m = max(v, s);

			f++;

		} else if (s < n) {

			if (s >= m || s <= v) {



				/*		for (int i = 0; i <= 1110; i++) {    //62-74的批注别乱开

							if (i > 99   && l <= 1000) {

								i = 0;

								l++;

							}

						*/	cout << "你犯规了！！！   ";




				//			}

				/*		cin >> q;
						if (g1 == 0) {
							g1++;
							if (q == l8) {
								continue;
							} else {
								return 0;
							}

						} else { */
				return 0;
				//		}



			}
			if (h == 0) {

				cout << "太小了，在 " <<  s << " 和 " << m - 1 << " 之间";

				v = min(s, m);

				f++;

				continue;

			}
			cout << "太小了，在 " <<  s << " 和 " << m << " 之间";

			v = min(s, m);

			f++;


		} else {

			for (long long i = 1; i <= 666; i ++) {
				/*
									if (i >= 665) {

										i = 1;

									}
									*/
				cout << i << " 恭喜你猜对了！！！    " ;

			}

			flag = true;

		}
		h++;

	}

	return 0;

}
