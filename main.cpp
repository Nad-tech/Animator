#include<\Users\dexte\source\repos\new projects\Animator\Animator\ConsoleWindow.h>
#include<\Users\dexte\source\repos\new projects\Animator\Animator\FileHandler.h>
#include<\Users\dexte\source\repos\new projects\Animator\Animator\FrameBuffer.h>
#include<vector>
#include<chrono>
#include <thread>

ConsoleWindow cWindow = ConsoleWindow("Animator", SCREEN_WIDTH, SCREEN_HEIGHT, FONT_WIDTH, FONT_HEIGHT);;

void writeFrame(FrameBuffer frame) {
	int x = frame.x;
	int y = frame.y;
	int width = frame.width;
	int height = frame.height;

	for (int i = x; i < x + width; i++) {
		for (int j = y; j < y + height; j++) {
			cWindow.setPixel(j * SCREEN_WIDTH + i, frame.characters[(j - y) * width + (i - x)], frame.colours[(j - y) * width + (i - x)]);
		}
	}
}


int main() {
	FileHandler fHandler = FileHandler();
	FrameBuffer firstFrame = FrameBuffer();
	FrameBuffer secondFrame = FrameBuffer();
	fHandler.loadFrameBuffer("SKELOPEN", firstFrame, 4, 4);
	fHandler.loadFrameBuffer("SKELCLOSE", secondFrame, 4, 4);

	vector<FrameBuffer> frameBuffers(2);

	frameBuffers[0] = firstFrame;
	frameBuffers[1] = secondFrame;

	int i = 0;
	
	while (1) {		
		std::chrono::milliseconds dura(100);
		std::this_thread::sleep_for(dura);

		writeFrame(frameBuffers[i]);

		i++;
		if (i == frameBuffers.size()) { i = 0; }
		
		cWindow.upDateWindow();
	}
	
	return 0;
}