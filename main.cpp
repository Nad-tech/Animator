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
			cWindow.setPixel(
				j * SCREEN_WIDTH + i, 
				frame.characters[(j - y) * width + (i - x)], 
				frame.colours[(j - y) * width + (i - x)]
			);
		}
	}
}


int main() {
	FileHandler fHandler = FileHandler();
	
	FrameBuffer firstFrame = FrameBuffer();
	FrameBuffer secondFrame = FrameBuffer();
	FrameBuffer thirdFrame = FrameBuffer();
	FrameBuffer fourthFrame = FrameBuffer();
	fHandler.loadFrameBuffer("SKELOPEN", firstFrame, 4, 4);
	fHandler.loadFrameBuffer("SKELCLOSE", secondFrame, 4, 4);
	fHandler.loadFrameBuffer("SKELWINK", thirdFrame, 4, 4);
	fHandler.loadFrameBuffer("SKELBLINK", fourthFrame, 4, 4);

	vector<FrameBuffer> frameBuffers(38);

	frameBuffers[0] = firstFrame;
	frameBuffers[1] = secondFrame;
	frameBuffers[2] = firstFrame;
	frameBuffers[3] = secondFrame;
	frameBuffers[4] = firstFrame;
	frameBuffers[5] = secondFrame;
	frameBuffers[6] = firstFrame;
	frameBuffers[7] = secondFrame;
	frameBuffers[8] = firstFrame;
	frameBuffers[9] = firstFrame;
	frameBuffers[10] = secondFrame;
	frameBuffers[11] = firstFrame;
	frameBuffers[12] = secondFrame;
	frameBuffers[13] = firstFrame;
	frameBuffers[14] = secondFrame;
	frameBuffers[15] = firstFrame;
	frameBuffers[16] = secondFrame;
	frameBuffers[17] = firstFrame;
	frameBuffers[18] = thirdFrame;
	frameBuffers[19] = firstFrame;
	frameBuffers[20] = secondFrame;
	frameBuffers[21] = firstFrame;
	frameBuffers[22] = secondFrame;
	frameBuffers[23] = firstFrame;
	frameBuffers[24] = secondFrame;
	frameBuffers[25] = firstFrame;
	frameBuffers[26] = secondFrame;
	frameBuffers[27] = firstFrame;
	frameBuffers[28] = firstFrame;
	frameBuffers[29] = secondFrame;
	frameBuffers[30] = firstFrame;
	frameBuffers[31] = secondFrame;
	frameBuffers[32] = firstFrame;
	frameBuffers[33] = secondFrame;
	frameBuffers[34] = firstFrame;
	frameBuffers[35] = secondFrame;
	frameBuffers[36] = firstFrame;
	frameBuffers[37] = fourthFrame;

	int i = 0;
	
	while (1) {		
		writeFrame(frameBuffers[i]);

		i++;
		if (i == frameBuffers.size()) { i = 0; }
		
		cWindow.upDateWindow();

		std::chrono::milliseconds dura(100);
		std::this_thread::sleep_for(dura);
	}
	
	return 0;
}