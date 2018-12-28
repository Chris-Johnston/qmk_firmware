# Chris Johnston's Keymap

Masssdrop CTRL keyboard

## Build Instructions

From the `qmk_firmware` directory, run the following:

```console
sudo make massdrop/ctrl:chris-johnston
./mdloader_linux --first --download massdrop_ctrl_chris-johnston.bin --restart
```

Assuming that the modloader tool and the required firmware are
both also under this directory also.
