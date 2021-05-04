#include "DoubleProperty.h"
#include "PropertyExpression.h"

class PropertyExpression;

DoubleProperty::DoubleProperty() 
	: DoubleProperty(0) { }

DoubleProperty::DoubleProperty(double d) 
	: value(d) { }

DoubleProperty::~DoubleProperty() {
	if (binding)
		delete binding;
}

double DoubleProperty::getValue() const {
	if (!binding) {
		return value;
	}
	return binding->eval();
}

void DoubleProperty::bind(PropertyExpression* exp) {
	if (binding)
		delete binding;
	binding = exp;
}

void DoubleProperty::unbind() {
	if (binding)
		delete binding;
	binding = nullptr;
}

void DoubleProperty::setValue(double d) {
	if (!binding)
		value = d;
}