# jackfix
fixing JACK from auto connection Mic to Playback

## Usage
Run it when ever jack connects from Mic to Playback<br>
`./jackfix <capture port num> <playback port num>`

## Build
`g++ ./jackfix.cpp -o jackfix -ljack`
