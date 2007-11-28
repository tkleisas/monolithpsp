#include <psprtc.h>
class TickCounter
{
	public:
	TickCounter()
	{
		sceRtcGetCurrentTick(&rtcBase);
		rtcTicksPerSecond = sceRtcGetTickResolution();
	};
	~TickCounter()
	{
	};
	
	unsigned int GetTicks()
	{
		u64 ticks=0;
		sceRtcGetCurrentTick(&ticks);
		
		u64 delta = ticks-rtcBase;
		u64 seconds = delta/rtcTicksPerSecond;
		u64 remainder = delta-(seconds*rtcTicksPerSecond);
		u64 millis = (remainder*1000)/rtcTicksPerSecond;
		unsigned int retval = seconds*1000+millis;
		return retval;
	};
	private:
	u64 rtcBase;
	u32 rtcTicksPerSecond;
	
	
};
