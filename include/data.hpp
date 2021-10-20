/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#ifndef INCLUDE_DATA_HPP_
#define INCLUDE_DATA_HPP_


/**
 * @brief Wrapper class for any encapsulate any datatype object
 * 
 * @tparam T - datatpye of the data being wrapped
 */
template <typename T>
class Data {
 public:
  /**
   * @brief Construct a new Data object
   * 
   */
  Data();

  /**
   * @brief parameterized constructer to  a new Data object
   * 
   * @param data 
   */
  explicit Data(T data);

  /**
   * @brief Destroy the Data object
   * 
   */
  virtual ~Data();

  /**
   * @brief Set the Data object
   * 
   * @param data of type T to be set in the _data attribute
   */
  virtual void setData(T data);

  /**
   * @brief Get the Data object
   * 
   * @return T returns the wrapped data of type T
   */
  virtual T getData() const;

 private:
  T _data;
};

#endif  // INCLUDE_DATA_HPP_
