# SmolBoi Hydrogen Line

This is the repository for the backend software for the "Smol Boi radio telescope" (SBRT) -- a personal project/attempt to make "meaningful" radio astronomy observations with a very small (~80cm in diameter) offset parabolic dish originally meant for Ku-band satellite communication.

Due to the inherent lack of gain offered by such a small satellite dish, the project is focused on clean observations of the [hydrogen line](https://en.wikipedia.org/wiki/Hydrogen_line) at around 1420 MHz. The sheer abundance of galactic and interstellar hydrogen means radiation at this frequency should, in theory, be detectable with almost any antenna connected to any radio receiver.

The SBRT uses an old peanut can as a [cantenna](https://youtu.be/8jEPK5Q3ux0) with a copper feed-through pin grounded to the can and cut tuned to 1420 MHz (1/4 wavelength). An sma cable feeds the signal to two LNAs connected in sequence. The amplified and filtered signal is finally transferred to an [RTL-SDR](https://www.rtl-sdr.com/rtl-sdr-quick-start-guide/).

The progression of this project will be in roughly this order:
1. Clear observation of the hydrogen line with the telescope pointed directly at the galactic core.
1. 24-hour measurement of galactic hydrogen passing overhead
1. Calculation of the galactic rotation curve
1. Bare metal implementation of the backend software 

## Project structure

* `SDRPlusPlus/` - git submodule of the nightly branch of SDR++
* `radioastro_hl/` - custom radio astronomy plugin that (hopefully sometime soon) displays an FFT graph, can save measurements to files for analysis, can save long exposure data, and can transfer data on a ZMQ device for processing by other devices. 
SDR++ already has an FFT window. 
We need an FFT window with a way longer time increment to actually see our measurement is the thing
* `baremetal/` - a bare metal OS (?) for the Raspberry Pi 5 that does all the core features of `HLPlugin` without the bloat of running on an operating system or even through SDR++ (very long term goal. TODO: how is this even going to work?).

## Dependencies

There has to be a better way of handling dependencies.

For Ubuntu, I installed:

- libairspy-dev, libairspyhf-dev, librtaudio-dev, libhackrf-dev, librtlsdr-dev, libiio-dev, libad9361-dev, and libsoapysdr-dev from apt
- libvolk from source
- fftw3, glfw, and zstd with vcpkg

I don't even want to think about what it'll be like on Windows.
Insert meme about dependency resolution in C++.

For WSL I probably want to do [this](https://www.linuxuprising.com/2021/03/how-to-get-sound-pulseaudio-to-work-on.html) if I want to actually hear any radio signals.

But given that this project is actually for hydrogen line detection I can do without it for now.

## Observations

tbd. nothing works yet, bluh.

## Related work
* [Job's Radio Telescope (JRT)](https://www.rtl-sdr.com/wp-content/uploads/2020/10/Rotation-Curve-with-JRT_English.pdf) accomplished these goals with an RTL-SDR and a 1.5 m dish.
* Hydrogen Line detection with an [RTL-SDR and a wifi dish](https://youtu.be/89B_C0x3-xI)
* [DSPIRA](https://wvurail.org/dspira-lessons/) for the basics, GNU radio backend, and a working horn telescope.

