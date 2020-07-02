import React, { Component } from 'react';

import { Container, Text,Title, Header, Content,Body, Subtitle, Form, Item, Input, Label, Button, Icon, Toast  } from 'native-base';
import { Alert } from 'react-native';

var styles = require('./style');

export default class Calculator extends Component {

    constructor(props) {
        super(props);
        this.state = {
            amount: undefined,
            percent: undefined,
            desiredPercent:undefined,
            result: undefined
        }
    }

    calculateResult = () => {
        //(A/B)*C-C
        var A = parseFloat(this.state.percent);
        var B = parseFloat(this.state.desiredPercent);
        var C = parseFloat(this.state.amount);

        if(B >= A)
        {
            Toast.show({
                text: "Желаемая крепость не может быть больше либо равна исходной крепости",
                buttonText: "Понятно",
                duration: 5000
            });
        }
        else if(A <= 0 || B <= 0 || C <= 0)
        {
            Toast.show({
                text: "Числа не могут быть отрицательными или равными нулю",
                buttonText: "Понятно",
                duration: 5000
            });
        }
        else{
            var num = (A/B)*C-C;
            var numRounded = Math.round(num * 100) / 100;
    
            if(isNaN(numRounded)){
                Toast.show({
                text: "Сначала нужно ввести все три цифры",
                buttonText: "Ладно",
                duration: 5000
            });}
            else
            {this.setState({result: numRounded  + ` л.`});}
        } 
    }

    clearFields = () => {
        this.setState({
            amount: undefined,
            percent: undefined,
            desiredPercent: undefined,
            result: undefined
        });

        Toast.show({
            text: "Все поля очищены",
            buttonText: "Ладно",
            duration: 5000
          });
    }


    changeAmount = (number) => {
        number = number.replace(/[^0-9.]/g, "")
        this.setState({amount: number});
    }

    changePercent = (number) => {
        this.setState({percent: number});
    }

    changeDesiredPercent = (number) => {
        this.setState({desiredPercent: number})
    }

    render() {
        return(
            <Content>
                <Text>Введите значения ниже</Text>
                <Form>
                    <Item>
                        <Label>Кол-во, л.</Label>
                    
                        <Input keyboardType = 'numeric' value={this.state.amount} onChangeText={number => this.changeAmount(number)}/>
                    </Item>
                    <Item>
                        <Label>Крепость, %</Label>
                        <Input keyboardType = 'numeric' value={this.state.percent}  onChangeText={number => this.changePercent(number)}/>
                    </Item>
                    <Item last>
                        <Label>Желаемая крепость, %</Label>
                        <Input keyboardType = 'numeric' value={this.state.desiredPercent}  onChangeText={number => this.changeDesiredPercent(number)}/>
                    </Item>
                </Form>
                <Text></Text>
                <Button rounded iconLeft onPress={() => this.calculateResult()} style={styles.calculateButton}>
                    <Icon name='calculator' />
                    <Text>Рассчитать</Text>
                </Button>
                <Text></Text>
                <Button rounded iconLeft onPress={() => this.clearFields()} style={styles.clearButton}>
                    <Icon name='trash' />
                    <Text>Очистить</Text>
                </Button>
                <Text style={styles.result}>{this.state.result}</Text>
        </Content>
        )


    }
}