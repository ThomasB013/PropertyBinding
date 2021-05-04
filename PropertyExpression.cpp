#include "PropertyExpression.h"
#include "DoubleProperty.h"



BinaryOp::BinaryOp(std::function<double(double, double)> op, PropertyExpression* l, PropertyExpression* r)
	:binOp(op), left(l), right(r) {}
BinaryOp::~BinaryOp() {
	left->~PropertyExpression();
	delete left;
	right->~PropertyExpression();
	delete right;
}
double BinaryOp::eval() const {
	return binOp(left->eval(), right->eval());
}


UnaryMinus::UnaryMinus(PropertyExpression* p) 
	: exp(p) {}
UnaryMinus::~UnaryMinus() {
	exp->~PropertyExpression();
	delete exp;
}
double UnaryMinus::eval() const {
	return -exp->eval();
}


PropertyLeaf::PropertyLeaf(DoubleProperty* p) 
	: doubleP(p) {}
PropertyLeaf::~PropertyLeaf() {}
double PropertyLeaf::eval() const {
	return doubleP->getValue();
}


ConstExpression::ConstExpression(double d) 
	: value(d) {}
ConstExpression::~ConstExpression() {}
double ConstExpression::eval() const {
	return value;
}


//helper functions to test:
PropertyExpression* plus(PropertyExpression* l, PropertyExpression* r) {
	return new BinaryOp(std::plus<double>(), l, r);
}
PropertyExpression* min(PropertyExpression* l, PropertyExpression* r) {
	return new BinaryOp(std::minus<double>(), l, r);
}
PropertyExpression* mul(PropertyExpression* l, PropertyExpression* r) {
	return new BinaryOp(std::multiplies<double>(), l, r);
}
PropertyExpression* div(PropertyExpression* l, PropertyExpression* r) {
	return new BinaryOp(std::divides<double>(), l, r);
}
PropertyExpression* neg(PropertyExpression* exp) {
	return new UnaryMinus(exp);
}
PropertyExpression* con(double d) {
	return new ConstExpression(d);
}
PropertyExpression* prop(DoubleProperty& p) {
	return new PropertyLeaf(&p);
}