#ifndef CRYPTO_INTERFACE_HPP
#define CRYPTO_INTERFACE_HPP

#include <vector>
#include <cstdint>

namespace Sovereign::Crypto {

    class ICryptoProvider {
    public:
        virtual ~ICryptoProvider() = default;
        virtual std::vector<uint8_t> encrypt(const std::vector<uint8_t>& data) = 0;
        virtual std::vector<uint8_t> decrypt(const std::vector<uint8_t>& data) = 0;
    };

} // namespace Sovereign::Crypto

#endif // CRYPTO_INTERFACE_HPP