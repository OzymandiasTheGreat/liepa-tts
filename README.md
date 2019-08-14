# [LIEPA](https://www.raštija.lt/liepa)

#### Lietuvių šneka valdomos paslaugos (Lithuanian speech controlled services)

This project aims to provide high quality digital Lithuanian speech services
for free.
So far there are several services provided at various stages of completeness,
such as Lithuanian speech recognizer and Lithuanian speech synthesizer.

This package wraps the latter.

## Dependencies

For this package (liepa-tts) to work you need synthesizer binaries which you'll
have to compile yourself.

The original sources can be acquired [here](http://liepaatnaujinimai.rastija.lt/sintezatorius/SintezesVariklis_LIEPAprojektas.zip)

To make it easier to build binaries for platforms other than Windows you can
acquire fixed-up sources here: [laba-diena-tts](https://github.com/OzymandiasTheGreat/laba-diena-tts)

Once you build binaries from the native-modules subtree make sure they are
available on LIBRARY_PATH (for building) and LD_LIBRARY_PATH (for runtime).

## Installation

I highly recommend [Poetry](https://poetry.eustace.io/)

`poetry add liepa-tts`

If you must, use pip:

`pip install liepa-tts`

You need numpy available for building C extension, so if you get errors first install that:

`pip install numpy`

## Usage

```python
from liepa_tts import liepa

# All strings must be encoded with Windows Baltic encoding
ENCODING = "cp1257"

# First parameter is the path to data directory
# Second parameter is the path to voice directory
# All paths must include trailing slash
# Returns error code
liepa.init("data/".encode(ENCODING), "data/Edvardas/".encode(ENCODING))

# Parameters:
# text: String that will be syntesized
# outSize: Integer. Typically this takes ~3072 per phoneme (letter), if it's too small you'll get buffer overflow errors
# speed: Integer. The larger the value the slower the voice will talk. Can be negative.
# tone: Integer. The pitch. Larger values make for higher pitch. Can be negative.
# Returns tuple (error code, ndarray). ndarray contains wav data without headers as array of integers.
text = "Laba diena. Kaip jums sekasi?".encode(ENCODING)
err, buff = liepa.synth(text, len(text) * 3072, 100, 0)

# Parameters:
# buff: The ndarray returned by liepa.synth() method
# filename: encoded path to output file
liepa.toWav(buff, "test.wav".encode(ENCODING))

# Call this when you're done to free resources
liepa.unload()
```

##### Notes:

Error codes produces by the synthesizer are defined in
`include/LithUSS_Error.h` so if you need more info on
the error you're getting check that file.

You can acquire the data files along with original sources [here](http://liepaatnaujinimai.rastija.lt/sintezatorius/SintezesVariklis_LIEPAprojektas.zip)

The files that must be present in `data/` directory are:

- `abb.txt`
- `duom.txt`
- `rules.txt`
- `skaitm.txt`

You should extract voice directories unmodified.

The `.wav` produce by the synthesizer is completely unoptimized and contains
a lot of silence. Therefor you should further process it before usage.
