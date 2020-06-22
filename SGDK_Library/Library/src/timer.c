#include "timer.h"

vu32 vtimer = 0;

/**
 *  \brief
 *      Returns elapsed subticks from console reset.
 *
 * Returns elapsed subticks from console reset (1/76800 second based).<br>
 * <b>WARNING:</b> this function isn't accurate because of the VCounter rollback.
 */
u32  getSubTick()
{
	return 0;
}

/**
 *  \brief
 *      Returns elapsed ticks from console reset.
 *
 * Returns elapsed ticks from console reset (1/300 second based).
 */
u32  getTick()
{
	return 0;
}

/**
 *  \brief
 *      Returns elapsed time from console reset.
 *
 *  \param fromTick
 *      Choose tick or sub tick (more accurate) calculation.
 *
 * Returns elapsed time from console reset (1/256 second based).
 */
u32  getTime(u16 fromTick)
{
	return 0;
}

/**
 *  \brief
 *      Returns elapsed time in second from console reset.
 *
 *  \param fromTick
 *      Choose tick or sub tick (more accurate) calculation.
 *
 * Returns elapsed time in second from console reset.<br>
 * Value is returned as fix32.
 */
fix32 getTimeAsFix32(u16 fromTick)
{
	return 0;
}

/**
 *  \brief
 *      Start internal timer (0 <= numtimer < MAXTIMER)
 *
 *  \param numTimer
 *      Timer number (0-MAXTIMER)
 */
void startTimer( u16 numTimer )
{
}

/**
 *  \brief
 *      Get elapsed subticks for specified timer.
 *
 *  \param numTimer
 *      Timer number (0-MAXTIMER)
 *  \param restart
 *      Restart timer if TRUE
 *
 * Returns elapsed subticks from last call to startTimer(numTimer).
 */
u32  getTimer(u16 numTimer, u16 restart)
{
	return 0;
}

/**
 *  \brief
 *      Wait for a certain amount of subticks.
 *
 *  \param subtick
 *      Number of subtick to wait for.
 *
 * <b>WARNING:</b> this function isn't accurate because of the VCounter rollback.
 */
void waitSubTick( u32 subtick )
{
}

/**
 *  \brief
 *      Wait for a certain amount of ticks.
 *
 *  \param tick
 *      Number of tick to wait for.
 *
 * <b>WARNING:</b> 5/6 (PAL/NTSC) ticks based timer so use 5/6 ticks as minimum wait value.
 */
void waitTick( u32 tick )
{
}

/**
 *  \brief
 *      Wait for a certain amount of millisecond.
 *
 *  \param ms
 *      Number of millisecond to wait for.
 *
 * <b>WARNING:</b> ~3.33 ms based timer is used when 'ms' is >= 100.
 */
void waitMs( u32 ms )
{
}