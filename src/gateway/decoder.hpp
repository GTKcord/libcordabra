#ifndef DECODER_HPP
#define DECODER_HPP

namespace libcordabra {
    class Decoder {
    public:
        // Decodes a buffer and uses the result to call the appropriate method in the parent according to a per-decoder
        // call
        // table
        virtual void decode() = 0;
    };
}
#endif /* DECODER_HPP */
