#include "product_manager.h"

#include <stdexcept>

namespace te
{

product_manager::product_manager() {}
void product_manager::load_from_file(const std::string & xml_filename)
{
    TiXmlDocument doc(xml_filename.c_str());
    if(!doc.LoadFile())
        throw std::runtime_error("Error while loading file " + xml_filename);

    TiXmlElement* root = doc.FirstChildElement( "te" );
    if(!root) throw std::runtime_error("No 'te' root node in file " + xml_filename);

    TiXmlElement* products = root->FirstChildElement( "products" );
    if(!products) throw std::runtime_error("No 'products' node in file " + xml_filename);

    TiXmlElement* productXml = products->FirstChildElement( "product" );
    do
    {
        m_products.push_back(new product(productXml));

    }
    while(productXml = productXml->NextSiblingElement("product"));

}

const product * product_manager::get_first_of( Predicate< const product*> P)
{
    for(product * p : m_products)
        if(P(p))
            return p;
    return NULL;
}
}
