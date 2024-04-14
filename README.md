# SmolBoi Hydrogen Line

This is the repository for the backend software for the "Smol Boi radio telescope" (SBRT) -- a personal project/attempt to make "meaningful" radio astronomy observations with a very small (~80cm in diameter) offset parabolic dish originally meant for Ku-band satellite communication.

Due to the inherent lack of gain offered by such a small satellite dish, the project is focused on clean obvservations of the [hydrigen line](https://en.wikipedia.org/wiki/Hydrogen_line) at around 1420 MHz. The sheer abundance of galactic and interstellar hydrogen mean radiation at this frequency should, in theory, be detectabl with almost any antenna connected to any radio receiver.

The SBRT uses an old peanut can as a [cantenna](https://youtu.be/8jEPK5Q3ux0) with a copper feedthrough pin groudned to the can and cut tuned to 1420 MHz (1/4 wavelength). An sma cable feeds the signal to two LNAs connected in sequence. The amplified and filtered signal is finally transferred to an [RTL-SDR](https://www.rtl-sdr.com/rtl-sdr-quick-start-guide/).

The progression of this project will be in roughly this order:
1. Clear observation of the hydrogen line with the telescope pointed directly at the galactic core.
1. 24-hour measurement of galactic hydrogen passing overhead
1. Calcualtion of the galactic rotation curve
1. Baremetal implementation of the backend software 

## Project structure

* `SDRPlusPlus/` - git submodule of the nightly branch of SDR++
* `HLPlugin/` - custom radio astronomy plugin that (hopefully sometime soon) displays an FFT graph, can save measurements to files for analysis, can save long exposure data, and can transfer data on a ZMQ device for processing by other devices.
* `baremetal/` - a baremetal OS for the raspebrry pi that does all the core features of `HLPlugin` without the bloat of running on an operating system or even through SDR++ (very long term goal).

## Observations

tbd. nothing works yet, bluh.

## Related work
* [Job's Radio Telescope (JRT)](https://www.rtl-sdr.com/wp-content/uploads/2020/10/Rotation-Curve-with-JRT_English.pdf) accomplished these goals with an RTL-SDR and a 1.5 m dish.
* Hydrogen Line detection with an [RTL-SDR and a wifi dish](https://youtu.be/89B_C0x3-xI)
* [DSPIRA](https://wvurail.org/dspira-lessons/)

