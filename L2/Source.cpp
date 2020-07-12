#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <cstdio>
#include <random>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <regex>
#include <tuple>
#include <map>
#include <set>

#include "triple.h"

using namespace std;

int main()
{
	triple a;
	triple b(2, 1);
	triple c(b);
	triple d(2, 6);
	triple e;

	cout << d << '\n';
	cin >> a;
	e = c - a;
	cout << e << '\n';

	cout << double(d) << ' ' << float(d) << '\n';

	e = triple(17, 22);

	cout << e * d << '\n';

	return 0;
}
