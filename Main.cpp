

#include <iostream>
#include <map>
#include "PropertyExpression.h"
#include "DoubleProperty.h"

using namespace std;

int main()
{
	DoubleProperty p(3);
	DoubleProperty q(4.5);
	cout << '\n' << "p: " << p.getValue() << '\n' << "q " << q.getValue() << '\n';
	
	p.bind(mul(prop(q), neg(min(con(3), con(5))))); //p bind (q * -(3-5)) = 2q.
	cout << '\n' << "p: " << p.getValue() << '\n' << "q " << q.getValue() << '\n';
	
	q.setValue(10);
	cout << '\n' << "p: " << p.getValue() << '\n' << "q " << q.getValue() << '\n';

	p.setValue(10);
	cout << '\n' << "p: " << p.getValue() << '\n' << "q " << q.getValue() << '\n';

	p.unbind();
	p.setValue(10);
	cout << '\n' << "p: " << p.getValue() << '\n' << "q " << q.getValue() << '\n';

	return 0;
}
