#include <stdio.h>

#define MAX_SENSORS 100
#define SAFE_DISTANCE 20.0

// Function to find the nearest obstacle
void findNearestObstacle(float *distance, int n,
                         float *nearest, int *sensor)
{
    int i;

    *nearest = *distance;
    *sensor = 0;

    for (i = 1; i < n; i++)
    {
        if (*(distance + i) < *nearest)
        {
            *nearest = *(distance + i);
            *sensor = i;
        }
    }
}

int main()
{
    float distance[MAX_SENSORS];
    float nearest;
    int n, i, sensor;

    printf("Enter number of sensors (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_SENSORS)
    {
        printf("Invalid number of sensors!\n");
        return 1;
    }

    // Input distance readings
    for (i = 0; i < n; i++)
    {
        printf("Enter distance from sensor %d (in cm): ", i + 1);
        scanf("%f", distance + i);

        if (*(distance + i) < 0)
        {
            printf("Invalid distance reading!\n");
            return 1;
        }
    }

    // Display sensor readings
    printf("\nSensor Distance Readings:\n");

    for (i = 0; i < n; i++)
    {
        printf("Sensor %d: %.2f cm\n",
               i + 1, *(distance + i));
    }

    // Find nearest obstacle using pointers
    findNearestObstacle(distance, n, &nearest, &sensor);

    // Display nearest obstacle
    printf("\nNearest Obstacle:\n");
    printf("Sensor Number: %d\n", sensor + 1);
    printf("Distance: %.2f cm\n", nearest);

    // Check safe distance
    if (nearest <= SAFE_DISTANCE)
    {
        printf("\nWARNING: Obstacle is too close!\n");
        printf("Stop the robot or change its direction.\n");
    }
    else
    {
        printf("\nSTATUS: Obstacle is at a safe distance.\n");
    }

    return 0;
}
