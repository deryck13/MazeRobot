void HUBW1_readQ ()
{
	if (HUBW1_step <= 0) //nu am facut nici un pas. nu doresc valori negative	
	{
		#ifdef Debug
		Serial.println("Debug: HUB1 " + HUBW1_step);
		#endif
		if (digitalRead(HUBW1_Q1APin))
		{
			if (digitalRead(HUBW1_Q1BPin))
			{
				#ifdef Debug
				Serial.println("Debug: HUB1 " + HUBW1_step);
				#endif
				return;
			}
			else
			{
				HUBW1_step++;
				Serial.println(HUBW1_step);
				return;
			}
		}
		else
			if (digitalRead(HUBW1_Q1BPin))
			{
				HUBW1_step++;
				Serial.println(HUBW1_step);
				return;
			}
			else
			{
				Serial.println(HUBW1_step);
				return;
			}
	}

	if (HUBW1_step > 0) //am facut deja un pas
	{
		#ifdef Debug
		Serial.println("Debug: HUB1 " + HUBW1_step);
		#endif
		if (digitalRead(HUBW1_Q1APin))
		{
			if (digitalRead(HUBW1_Q1BPin))
			{
				HUBW1_step--;
				Serial.println(HUBW1_step);							
				#ifdef Debug
				Serial.println("Debug: HUB1 " + HUBW1_step);
				#endif
				return;
			}
			else
			{
				HUBW1_step++;
				Serial.println(HUBW1_step);
				return;
			}
		}
		else
			if (digitalRead(HUBW1_Q1BPin))
			{
				HUBW1_step++;
				Serial.println(HUBW1_step);
				return;
			}
			else
			{
				HUBW1_step--;
				Serial.println(HUBW1_step);
				return;
			}
	}
};

void HUBW2_readQ ()
{
	if (HUBW2_step <= 0) //nu am facut nici un pas. nu doresc valori negative	
	{
		#ifdef Debug
		Serial.println("Debug: HUB2 " + HUBW2_step);
		#endif
		if (digitalRead(HUBW2_Q1APin))
		{
			if (digitalRead(HUBW2_Q1BPin))
			{
				#ifdef Debug
				Serial.println("Debug: HUB2 " + HUBW2_step);
				#endif
				return;
			}
			else
			{
				HUBW2_step++;
				Serial.println(HUBW2_step);
				return;
			}
		}
		else
			if (digitalRead(HUBW2_Q1BPin))
			{
				HUBW2_step++;
				Serial.println(HUBW2_step);
				return;
			}
			else
			{
				Serial.println(HUBW2_step);
				return;
			}
	}

	if (HUBW2_step > 0) //am facut deja un pas
	{
		#ifdef Debug
		Serial.println("Debug: HUB2 " + HUBW2_step);
		#endif
		if (digitalRead(HUBW2_Q1APin))
		{
			if (digitalRead(HUBW2_Q1BPin))
			{
				HUBW2_step--;
				Serial.println(HUBW2_step);							
				#ifdef Debug
				Serial.println("Debug: HUB2 " + HUBW2_step);
				#endif
				return;
			}
			else
			{
				HUBW2_step++;
				Serial.println(HUBW2_step);
				return;
			}
		}
		else
			if (digitalRead(HUBW2_Q1BPin))
			{
				HUBW2_step++;
				Serial.println(HUBW2_step);
				return;
			}
			else
			{
				HUBW2_step--;
				Serial.println(HUBW2_step);
				return;
			}
	}
};

int state_equality(int HUBW2_step2, int HUBW1_step1)
{

	if (HUBW1_step1 == HUBW2_step2)
	{
		equal = true;
		return 0;
	}

	if (HUBW1_step1 > HUBW2_step2)
	{
		equal = false;
		directions = 0;
	}
	
	if (HUBW1_step1 < HUBW2_step2)
	{
		equal = false;
		directions = 1;
	}
	return 1;
};

