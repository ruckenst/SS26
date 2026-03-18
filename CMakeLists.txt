cmake_minimum_required(VERSION 3.30)
project(SS26)

set(CMAKE_CXX_STANDARD 20)

add_executable(SS26
        main.cpp
        FeeStrategy.h
        TransferFeeStrategy.cpp
        TransferFeeStrategy.h
        PayPalFeeStrategy.cpp
        PayPalFeeStrategy.h
        MasterCardFeeStrategy.cpp
        MasterCardFeeStrategy.h
        FeeStrategyFactory.cpp
        FeeStrategyFactory.h
        PaymentProvider.h
        PaymentRequest.cpp
        PaymentRequest.h
        PaymentHandler.cpp
        PaymentHandler.h
        PaymentStartedHandler.cpp
        PaymentStartedHandler.h
        PaymentFinishedHandler.cpp
        PaymentFinishedHandler.h
        PaymentProcessingHandler.cpp
        PaymentProcessingHandler.h
)