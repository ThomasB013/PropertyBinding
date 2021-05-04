#pragma once
class DoubleProperty; //forward declaration

#include <functional>

class PropertyExpression
{
public:
	virtual double eval() const = 0;
	virtual ~PropertyExpression() {}
};

class BinaryOp : public PropertyExpression {
public:
	BinaryOp(std::function<double(double, double)> op, PropertyExpression* l, PropertyExpression* r);
	virtual ~BinaryOp();
	virtual double eval() const;
private:
	std::function<double(double, double)> binOp;
	PropertyExpression* left, * right;
};

class UnaryMinus : public PropertyExpression {
public:
	UnaryMinus(PropertyExpression* p);
	virtual ~UnaryMinus();
	virtual double eval() const;
private:
	PropertyExpression* exp;
};

class PropertyLeaf : public PropertyExpression {
public:
	PropertyLeaf(DoubleProperty* p);
	virtual ~PropertyLeaf();
	virtual double eval() const;
private:
	DoubleProperty* doubleP;
};

class ConstExpression : public PropertyExpression {
public:
	ConstExpression(double d);
	virtual ~ConstExpression();
	virtual double eval() const;
private:
	double value;
};

//helper functions to test:
PropertyExpression* add(PropertyExpression* l, PropertyExpression* r);
PropertyExpression* min(PropertyExpression* l, PropertyExpression* r);
PropertyExpression* mul(PropertyExpression* l, PropertyExpression* r);
PropertyExpression* div(PropertyExpression* l, PropertyExpression* r);
PropertyExpression* neg(PropertyExpression* exp);
PropertyExpression* con(double d);
PropertyExpression* prop(DoubleProperty& p);