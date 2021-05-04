#pragma once
class Formula;  //forward declaration
#include "PropertyExpression.h"

//PropertyExpression* operator+(PropertyExpression* l, PropertyExpression* r);
//will give an error, so we need to bind to formula (see Formula.h).

class DoubleProperty
{
public:
	DoubleProperty();
	DoubleProperty(double d);
	~DoubleProperty();

	void bind(PropertyExpression* exp);
	void unbind();

	double getValue() const;
	void setValue(double d);

private:
	double value;
	PropertyExpression* binding;
};

