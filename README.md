# libspeedwm

libspeedwm is a minimal program for interacting with speedwm through the shell. It allows you to run signals but also perform actions. It is written in C because speedwm itself is written in C. It only has one dependency; libX11 used to set the root window name.
## Why should I use libspeedwm?

While yes, you *can* run signals manually (speedwm -s "#cmd:10"), this is slightly risky. If speedwm gets updated and its signals get changed, your script will be using the old signals potentially breaking your script completely. libspeedwm solves this because libspeedwm can and will be updated alongside speedwm which means all of the actions are going to work on the latest version.

## What are the downsides of libspeedwm?

This does come with a few downsides though. First is that libspeedwm will be a dependency for your script/project. It is an external dependency and is not bundled with speedwm itself.

Secondly, if the user is on an old speedwm version, the libspeedwm version must also be old or scripts will break just the same as using signals normally. This comes with a huge problem: there are bugs in the old libspeedwm version.

## Usage

See `libspeedwm --help` for more information.

## Download

The latest and previous releases of libspeedwm can be found <a href="https://codeberg.org/speedie/libspeedwm">here</a>. See Releases for more information.</p>

## License

libspeedwm is licensed under the GNU General Public License version 3.0. See LICENSE file for more information.
