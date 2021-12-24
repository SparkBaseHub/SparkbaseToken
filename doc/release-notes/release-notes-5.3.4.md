Sparkbase version *5.3.4* is now available from:  <https://github.com/SparkBaseHub/SparkbaseToken/releases>

This is a new minor version release, including various bug fixes and performance improvements, as well as an updated community info display.

Please report bugs using the issue tracker at github: <https://github.com/SparkBaseHub/SparkbaseToken/issues>


Mandatory Update
==============

Sparkbase Token v5.3.4 is a mandatory update for all users. This release contains new consensus rules and improvements that are not backwards compatible with older versions. Users will need to update their clients before enforcement of this update goes into effect.

Masternodes will need to be restarted once both the masternode daemon and the controller wallet have been upgraded.
If you are running a Masternode over Tor, please read the "How To Upgrade" section.

Note: In preparation for the enforcement, upgraded peers will start rejecting non-upgraded peers few hours before the enforcement block height, we recommend everyone to be updated at max a day before the final time.

How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has completely shut down (which might take a few minutes for older versions), then run the installer (on Windows) or just copy over /Applications/Sparkbase (on Mac) or sparkd/spark-qt (on Linux).

Sapling Parameters
==================

In order to run, as all versions after 5.0.0, Sparkbase Token requires two files, `sapling-output.params` and `sapling-spend.params` (with total size ~50 MB), to be saved in a specific location.

For the following packages, no action is required by the user:
- macOS release `dmg` binaries will use the params that are bundled into the .app bundle.
- Windows installer `.exe` will automatically copy the files in the proper location.
- Linux `PPA/Snap` installs will automatically copy the files in the proper location.

For the other packages, the user must save the param files in the proper location:
- macOS/Linux `tar.gz` tarballs include a bash script (`install-params.sh`) to copy the parameters in the appropriate location.
- Windows `.zip` users need to manually copy the files from the `share/sparkbase` folder to the `%APPDATA%\SparkbaseParams` directory.
- self compilers can run the script from the repository sources (`params/install-params.sh`), or copy the files directly from the `params` subdirectory.

Compatibility
==============

Sparkbase Token is extensively tested on multiple operating systems using the Linux kernel, macOS 10.12+, and Windows 10 and later.

From Sparkbase Token v5.3 onwards, macOS versions earlier than 10.12 are no longer supported.

Sparkbase Token should also work on most other Unix-like systems but is not frequently tested on them.

The node's known peers are persisted to disk in a file called `peers.dat`. The format of this file has been changed in a backwards-incompatible way in order to accommodate the storage of Tor v3 and other BIP155 addresses. This means that if the file is modified by v5.3 or newer then older versions will not be able to read it. Those old versions, in the event of a downgrade, will log an error message "Incorrect keysize in addrman deserialization" and will continue normal operation as if the file was missing, creating a new empty one.
