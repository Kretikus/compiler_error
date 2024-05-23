
#include <botan/auto_rng.h>
#include <botan/block_cipher.h>
#include <botan/base64.h>
#include <botan/bcrypt.h>
#include <botan/block_cipher.h>
#include <botan/cipher_mode.h>
#include <botan/data_src.h>
#include <botan/ecdsa.h>
#include <botan/hash.h>
#include <botan/hex.h>
#include <botan/mac.h>
#include <botan/pubkey.h>
#include <botan/pkcs8.h>
#include <botan/system_rng.h>
#include <botan/x509_key.h>

namespace BotanBackend
{
  class PubKeyImpl;
  class PrvKeyImpl;
}

class BotanBackend::PubKeyImpl
{
public:
  Botan::ECDSA_PublicKey myPubKey;
};

class BotanBackend::PrvKeyImpl
{
public:
  Botan::ECDSA_PrivateKey myPrvKey;
};


class CErrorTest
{
public:
  void GetPublicKey() {
    // Internal compiler error on the following line
    auto* impl = new BotanBackend::PubKeyImpl{ Botan::ECDSA_PublicKey(myImpl->myPrvKey.algorithm_identifier(), myImpl->myPrvKey.public_key_bits()) };
  }

  std::shared_ptr< BotanBackend::PrvKeyImpl> myImpl;
};

int main(int argc, char* argv[])
{

}