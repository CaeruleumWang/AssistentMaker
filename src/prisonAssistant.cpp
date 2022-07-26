#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

cv::Mat drawPrisonAssistant(cv::Mat image, cv::Scalar color, int dividers, int lineWidth, bool isVertical){
	
	cv::Mat result = image.clone();

	int offset = lineWidth/2;

	int trimmedHeight = result.size().height - (offset*2);
	int trimmedWidth = result.size().width - (offset*2);
	
	int perHeight = trimmedHeight/dividers;
	int perWidth = trimmedWidth/dividers;

	if(isVertical){
		for(int i=0; i<dividers+1; i++){
			cv::Point verticalStart = cv::Point(offset+perWidth*i, offset);
			cv::Point verticalEnd = cv::Point(offset+perWidth*i, offset+trimmedHeight);
			cv::line(result, verticalStart, verticalEnd, color, lineWidth, cv::LINE_8);
		}
	}else{
		for(int i=0; i<dividers+1; i++){
			cv::Point horizontalStart = cv::Point(offset, offset+perHeight*i);
			cv::Point horizontalEnd = cv::Point(offset+trimmedWidth, offset+perHeight*i);
			cv::line(result, horizontalStart, horizontalEnd, color, lineWidth, cv::LINE_8);
		}
	}

	return result;
}
