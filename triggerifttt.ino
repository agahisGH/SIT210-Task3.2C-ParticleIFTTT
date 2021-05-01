// NOTE: using mock-up values instead (as recommended on the task sheet), due to not having an ambient light sensor

// ***
// defining a threshold for light level at 250
// after some research, came to conclusion that anything after a lux (unit measurement of light) of approximately 250 is considered to be "bright light"
// therefore for the purpose of this task, we will assume anything after this level, is considered to have sufficient levels of light
// and anything less than or equal to 250, will be considered dark

void setup()
{
    // no need for anything here since we are creating mock-up values
}

void loop()
{
    // creating a local variable "level" to represent the light level taken from the room where the terrarium is located
    // it will generate a random integer between the values of 150-350 each time for testing purposes
    int level = random(150, 350);
    
    // refer above to (***) section for explanation...
    if (level <= 250)
    {
        // the IFTTT applet that I created will be triggered by the event name: "updated_light_level"
        // and only if it contains the event: "DARK"
        // the user should only recieve a notification when its detected the light level as dark
        Particle.publish("updated_light_level", "DARK");
        // delays for 1 minute
        delay(60000);
    } else {
        // the IFTTT applet that I created will be triggered by the event name: "updated_light_level"
        // and only if it contains the event: "LIGHT"
        // the user should only recieve a notification when its detected the light level as light
        Particle.publish("updated_light_level", "LIGHT");
        // delays for 1 minute
        delay(60000);
    }
}