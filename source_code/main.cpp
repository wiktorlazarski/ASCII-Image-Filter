#include "image_processing/image_converters/rgb_to_ascii.h"
#include "tools/console_logger.h"

int main(int argc, char* argv[])
{
	try {
		if (argc < 3) {
			throw std::invalid_argument("Input or output not specified");
		}
		const RGBImage input_img(argv[1]);
		ConsoleLogger::get_instance().log("Image file " + std::string(argv[1]) + " load successfully\n");

		bool conversion_complete = false;
		std::thread t([&conversion_complete]() {
			while (!conversion_complete) {
				ConsoleLogger::get_instance().log("Converting image");
				for (int i = 0; i < 2; i++) {
					ConsoleLogger::get_instance().log(".");
					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}
				ConsoleLogger::get_instance().log("\r");
			}
		});

		std::unique_ptr<AsciiImage> ascii_img(RGBToAscii::get_instance().convert(input_img));
		conversion_complete = true;
		t.join();

		ConsoleLogger::get_instance().log("\nWriting converted image to file : " + std::string(argv[2]));
		ascii_img->fwrite(argv[2]);
		ConsoleLogger::get_instance().log("\nConversion finished successfully !");
	}
	catch (std::exception& ex) {
		ConsoleLogger::get_instance().log(ex.what());
	}
	catch (...) {
		ConsoleLogger::get_instance().log("Unknown exception");
		return -1;
	}

	return 0;
}