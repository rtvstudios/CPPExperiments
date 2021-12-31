
import Shape;

int main(int argc, char **argv) {
	auto triangle = ShapeCreator::create("Triangle");
	triangle->draw();
	return 0;
}

