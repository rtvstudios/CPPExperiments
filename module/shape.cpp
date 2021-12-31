module;

import <string>;
import <memory>;
import <iostream>;

export module Shape;

export class Shape {
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Triangle: public Shape {
public:
	static std::string name() {
		return "Triangle";
	}

	void draw() override {
		std::cout << "Drawing Triangle" << std::endl;
	}
};

export class ShapeCreator {
public:
	static std::unique_ptr<Shape> create(const std::string &name) {
		if (name == Triangle::name()) {
			return std::make_unique<Triangle>();
		}
		return nullptr;
	}
};

