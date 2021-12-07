Sparkbase version *1.0.7* is now available from:  <https://github.com/SparkBaseHub/SparkbaseToken/releases>

This is a new minor version release, including various bug fixes and performance improvements, as well as an updated community info display.

Please report bugs using the issue tracker at github: <https://github.com/SparkBaseHub/SparkbaseToken/issues>


Mandatory Update
==============

Sparkbase v1.0.7 is a mandatory update for all users.

How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has completely shut down (which might take a few minutes for older versions), then run the installer (on Windows) or just copy over /Applications/BASE-Qt (on Mac) or based/base-qt (on Linux).


Notable Changes
==============

zBASE Updates
--------------

### zBASE Staking

zBASE Staking is here! zBASE staking will be activated by default after pre-sale phase. 
Note: To activate zBASE minting, click the privacy tab, then the zBASE Control button then expand the arrows next to the desired denomination.


### Deterministic zBASE Seed Keys

zBASE is now associated with a deterministic seed key. With this seed key, users are able to securely backup their zBASE outside of the wallet that the zBASE had been minted on. zBASE can also be transferred from wallet to wallet without the need of transferring the wallet data file.


### Updated zBASE minting

zBASE minting now only requires 1 further mint (down from 2) to mature. zBASE mints still require 20 confirmations.  Mints also require that the 'second' mint is at least two checkpoints deep in the chain (this was already the case, but the logic was not as precise).


### zBASE Search

Users will now have the ability to search the blockchain for a specific serial # to see if a zBASE denomination has been spent or not.


BASE/zBASE Staking and Masternode Rewards
--------------

### BASE, zBASE and Masternode Payment Schedule

To encourage the use of zBASE and increase the BASE zerocoin anonymity set, the BASE payment schedule has been changed to the following:

If a user staking zBASE wins the reward for their block, the following zBASE reward will be: 
- 3 zBASE (3 x 1 denominations) rewarded to the staker, 2 BASE rewarded to the masternode owner and 1 BASE available for the budget. This is a total block reward of 6 BASE, up from 5.

If a user staking BASE wins the reward, the following amounts will be rewarded: 
- 2 BASE to the BASE staker, 3 BASE to the Masternode owner and 1 BASE available for the budget. This is a total block reward of 6 BASE, up from 5.


### Return change to sender when minting zBASE

Previously, zBASE minting would send any change to a newly generated "change address". This has caused confusion among some users, and in some cases insufficient backups of the wallet. The wallet will now find the contributing address which contained the most BASE and return the change from a zBASE mint to that address.


User Experience
--------------

### Graphical User Interface

The visual layout of the BASE Qt wallet has undergone a near-complete overhaul.
A new 'vertical tab' layout is now being used instead of the prior 'horizontal tab' layout, as well as a completely new icon set.
The overview tab has been simplified greatly to display only balances that are active or relevant, zero-balance line items are hidden by default to avoid clutter.


### Wallet Options

There have been a number of changes to the tasks that you are able to perform from the wallet options. Users will now have the ability to do the following: 
-	Enable and disable the auto zBASE minting feature. This is enabled by default and the enablezeromint=0 setting in the base.conf file will overwrite the GUI option.
-	The percentage of autominted zBASE can now be set from 1 to 100, changed from 10 – 100.
-	The stake split threshold can now be set VIA the wallet options. This setting is an advanced feature for those wishing to remain staking regular BASE.
-	“Unlock for staking and anonymization only” is now selected by default when unlocking the wallet from the User Interface


### In-wallet Ban Management

Peer bans are now manageable through the Peers tab of the tools window. Peers can be banned/unbanned at will without the need to restart the wallet client. No changes have been made to the conditions resulting in automatic peer bans.


Backup to external devices / locations
--------------

### Summary

 The BASE wallet can now have user selected directories for automatic backups of the wallet data file (wallet.dat). This can be set by adding the following lines to the base.conf file, found in the BASE data directory.
- backuppath = <directory / full path>
- zbasebackuppath = <directory / full path>
- custombackupthreshold = <backup limit>
Note: System write permissions must be appropriate for the location the wallet is being saved to.

* Configured variables display in the _Wallet Repair_ tab inside the _Tools Window / Dropdown Menu_
* Allows for backing up wallet.dat to the user set path, simultaneous to other backups
* Allows backing up to directories and files, with a limit (_threshold_) on how many files can be saved in the directory before it begins overwriting the oldest wallet file copy.


### Details:

* If path is set to directory, the backup will be named `wallet.dat-<year>-<month>-<day>-<hour>-<minute>-<second>`
* If zBASE backup, auto generated name is `wallet-autozbasebackup.dat-<year>-<month>-<day>-<hour>-<minute>-<second>`
* If path set to file, backup will be named `<filename>.dat`
* walletbackupthreshold enables the user to select the maximum count of backup files to be written before overwriting existing backups.


### Example:

* -backuppath=/\<mynewdir>/        
* -walletbackupthreshold=2

Backing up 4 times will result as shown below


                date/time
    backup #1 - 2018-12-20-00-04-00  
    backup #2 - 2018-12-21-04-20-00  
    backup #3 - 2018-12-22-00-20-04  
    backup #4 - 2018-12-23-20-04-00  
    
    1.
        /<mynewdir>/
            wallet.dat-2018-12-20-00-04-00
    2.
        /<mynewdir>/
            wallet.dat-2018-12-20-00-04-00
            wallet.dat-2018-12-21-04-20-00
    3.
        /<mynewdir>/
            wallet.dat-2018-12-22-00-20-04
            wallet.dat-2018-2-21-04-20-00
    4.
        /<mynewdir>/
            wallet.dat-2018-12-22-00-20-04
            wallet.dat-2018-12-23-20-04-00
            


BASE Daemon & Client (RPC Changes)
--------------

### RPC Ban Management

The BASE client peer bans now have additional RPC commands to manage peers. Peers can be banned and unbanned at will without the need to restart the wallet client. No changes have been made to the conditions resulting in automatic peer bans. New RPC commands: `setban`, `listbanned`, `clearbanned`, and `disconnectnode`


### Random-cookie RPC authentication

When no `-rpcpassword` is specified, the daemon now uses a special 'cookie' file for authentication. This file is generated with random content when the daemon starts, and deleted when it exits. Its contents are used as authentication token. Read access to this file controls who can access through RPC. By default it is stored in the data directory but its location can be overridden with the option `-rpccookiefile`.
This is similar to Tor's CookieAuthentication: see https://www.torproject.org/docs/tor-manual.html.en 
This allows running based without having to do any manual configuration.


### New RPC command
`getfeeinfo`

This allows for a user (such as a third party integration) to query the blockchain for the current fee rate per kb, and also get a suggested rate per kb for high priority tx's that need to get added to the blockchain asap.


### New RPC command 
`findserial`

Search the zerocoin database for a zerocoinspend transaction that contains the given serial. This will be a helpful tool for the BASE support group, which often times sees users say "I didn't spend that zBASE". This RPC call allows for support to grab the serial, and then find the spend tx on the chain.


### SwiftX Raw Transactions

 When creating a raw transaction, it is now possible to create the transaction as a SwiftX transaction. See the updated help documentation for the `createrawtransaction` RPC command.

Technical Changes
--------------

### Migration to libevent based http server

The RPC and REST interfaces are now initialized and controlled using standard libevent instead of the ad-hoc pseudo httpd interface that was used previously. This change introduces a more resource friendly and effective interface.


### New Notification Path 
`blocksizenotify`

A new notification path has been added to allow a script to be executed when receiving blocks larger than the 1MB legacy size. This functions similar to the other notification listeners (`blocknotify`, `walletnotify`, etc).

### Autocombine changes

The autocombine feature was carrying a bug leading to a significant CPU overhead when being used. The function is now called only once initial blockchain download is finished. It's also now avoiding to combine several times while under the threshold in order to avoid additional transaction fees. Last but not least, the fee computation has been changed and the dust from fee provisioning is returned in the main output.


### SOCKS5 Proxy bug

When inputting wrong data into the GUI for a SOCKS5 proxy, the wallet would crash and be unable to restart without accessing hidden configuration. This crash has been fixed.

Minor Enhancements
--------------

-	Set zBase automint to false for pre-sale phase
-	Updates to zBASE spends to avoid segfaults
-	Updates to configuration will now reflect on the privacy tab
-	Fixed a  bug that would not start masternodes from the BASE-Qt masternodes tab
-	Updated BASE-Qt tooltips
-	Icon added to the wallet GUI to reflect the status of autominting (active / inactive)
-	Updated errors causing the blockchain to corrupt when experiencing unexpected wallet shutdowns
-	Updated RPC help outputs & removed the deprecated obfuscation. 
-	Refactored code
-	Various bug fixes
-	Updated documentation

