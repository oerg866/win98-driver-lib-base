NVMe driver for Windows 9x.

Base: nvme2k 1.0.0.2 https://github.com/techomancer/nvme2k
Changes: Port for Windows 9x, 64-bit LBA & Fixes

1. Generic
- added SCSI 64-bit LBA commands processing (large drives support).
  Tested on Windows 9x ONLY
- fixed controler shutdown code
- speed up of command queueing and it is less CPU consuming
- fixed enormously low speed or false positive errors on executing
  of large size requests
- various code rectifications

2. Windows 9x specific
- port with 2 bug fixes
- install script nvme9x.inf written

Install and uninstall as usual hardware, nothing specific.
