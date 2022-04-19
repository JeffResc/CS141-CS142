#include<iostream>

int main()
{
	// Declare our variables
	float RoadRunnerSpeed;
	float LairToLairDistance;
	float RoadRunnerBreakTime;
	float TotalRoadRunnerTravelTime;
	float WileECoyoteTravelTime;
	float WileECoyoteSpeed;

	// Set the variables given by the homework assignment
	LairToLairDistance = 30;
	RoadRunnerSpeed = 15;
	RoadRunnerBreakTime = 15;

	// Divide RoadRunnerSpeed by 60 to convert from miles per hour to miles per minute
	RoadRunnerSpeed = RoadRunnerSpeed / 60;

	// Calculate TotalRoadRunnerTravelTime by dividing total distance by total time and adding in the total break time
	TotalRoadRunnerTravelTime = (LairToLairDistance / RoadRunnerSpeed) + RoadRunnerBreakTime;

	// Since RoadRunner and WileECoyote arrive at the same time, their total travel times should be the same
	WileECoyoteTravelTime = TotalRoadRunnerTravelTime;

	// Calculate Wile E. Coyote's Speed by dividing Wile E. Coyote's Travel Time by the total distance traveled
	WileECoyoteSpeed = WileECoyoteTravelTime / LairToLairDistance;

	// Prfloat out our calculations
	std::cout << "RoadRunnerSpeed: " << RoadRunnerSpeed << " (miles per minute)" << std::endl;
	std::cout << "LairToLairDistance: " << LairToLairDistance << " (miles)" << std::endl;
	std::cout << "RoadRunnerBreakTime: " << RoadRunnerBreakTime << " (minutes)" << std::endl;
	std::cout << "TotalRoadRunnerTravelTime: " << TotalRoadRunnerTravelTime << " (minutes)"<< std::endl;
	std::cout << "WileECoyoteTravelTime: " << WileECoyoteTravelTime << " (minutes)" << std::endl;
	std::cout << "WileECoyoteSpeed: " << WileECoyoteSpeed << " (miles per minute)" << std::endl;
}
