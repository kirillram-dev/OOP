#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include <../catch/catch.hpp>
#include "../Car/Car.h"

SCENARIO("Car", "[car]")
{
	GIVEN("Car is turned off")
	{
		CCar car;
		// Машина изначально выключена
		WHEN("Car is turned off by default")
		{
			REQUIRE(!car.IsTurnedOn());
			CHECK(car.GetDirection() == Direction::Stop);
			CHECK(car.GetSpeed() == 0);

			// не может переключать канал в выключенном состоянии
			/*THEN("cant select channel when turned off")
			{
				CHECK(!tv.SelectChannel(87));
			}*/
		}
	}
}